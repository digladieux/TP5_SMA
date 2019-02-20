/**
 * \file Ground.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian ()
 * \brief Fichier d'implementation d'un terrain
 * \date 2018-12-06
 */

#include "../header/Ground.hpp"
#include "../header/MaleCharacter.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/Exception.hpp"
#include <iostream>
#include <exception>

/**
 * \brief Variable statique du nombre de terrain genere a 0 ;
 */
unsigned int Ground::ground_number = 0;

/**
 * \fn Ground::Ground(GROUND_TYPE type)
 * \brief Constructeur de la classe Ground
 * \param type Type de terrain
 */
Ground::Ground(GROUND_TYPE type) : ground_id(ground_number), ground_type(type), vector_character(0)
{
    ground_number++;
}
/* TODO : clone avec les character ?? Meme ne pas refaire de new et les placer direct dans le terrain ?? */

/**
 * \fn Ground &Ground::operator=(const Ground &new_ground)
 * \brief Surcharge de l'operateur d'affectation
 * \param &new_ground Terrain que l'on veut copier 
 * \return Le nouveau terrain copie
 */
Ground &Ground::operator=(const Ground &new_ground)
{
    if (this != &new_ground) /* On verifie que le terrain n'est pas le meme que l'on veut copier */
    {
        ground_id = new_ground.ground_id;
        ground_type = new_ground.ground_type;
       
        for (unsigned int k = 0; k < new_ground.vector_character.size(); k++)
        {
             Character *character = nullptr;
            if (new_ground.getCharacter(k)->getCharacterGender() == SEX::MALE)
            {
                character = new MaleCharacter(*static_cast<MaleCharacter*>(new_ground.getCharacter(k)));
            }
            else
            {
                character = new FemaleCharacter(*static_cast<FemaleCharacter*>(new_ground.getCharacter(k)));
            }
            this->addCharacter(character);
        }
    }
    return *this;
}

/**
 * \fn Ground::Ground(GROUND_TYPE type, unsigned int id, std::vector<Character *> vector_character)
 * \brief Constructeur de la classe Ground
 * \param type Type de terrain
 * \param id identifiant unique du terrain
 * \param vector_character Vecteur content les personnages allant sur cette case
 */
Ground::Ground(GROUND_TYPE type, unsigned int id, std::vector<Character *> vector_character) : ground_id(id), ground_type(type)
{
    Character *old_character = nullptr;
    Character *character = nullptr;
    for (unsigned int k = 0; k < vector_character.size(); k++)
    {
        old_character = vector_character[k];
        if (old_character->getCharacterGender() == SEX::MALE)
        {
            character = new MaleCharacter(*static_cast<MaleCharacter*>(old_character));
        }
        else
        {
            character = new FemaleCharacter(*static_cast<FemaleCharacter*>(old_character));
        }
        this->addCharacter(character);
    }
}
/**
 * \brief Constructeur de copie de la classe Ground
 * \param &ground Le terrain que l'on veut copier
 */

Ground::Ground(const Ground &ground) : ground_id(ground.ground_id), ground_type(ground.ground_type)
{
    addCharacterGround(ground) ;
}

/**
 * \fn Ground::Ground(const Ground &ground, GROUND_TYPE type)
 * \brief Constructeur de copie de la classe Forest avec sa classe mere en parametre
 * \param &ground Copie du terrain que l'on veut faire
 * \param type Type de terrain
 */
Ground::Ground(const Ground &ground, GROUND_TYPE type) : ground_id(ground.ground_id), ground_type(type)
{
    addCharacterGround(ground) ;
}

/**
 * \fn Ground* Ground::clone() const
 * \brief Constructeur dynamique de la classe Ground. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de CollectionPoint que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
Ground* Ground::clone() const
{
    return new Ground(*this);
}

/*TODO : meme que au dessus avec le clone pour addCharacterGround  */

/**
 * \fn void Ground::addCharacterGround(const Ground& ground) noexcept
 * \brief Methode d'ajout de personnage sur un terrain lors du lancement d'un constructeur de copie
 * \param &ground Terrain ou l'on veut ajouter les personnages
 */ 
void Ground::addCharacterGround(const Ground& ground) noexcept
{
    for (unsigned int k = 0; k < ground.vector_character.size(); k++)
    {
        Character *character = nullptr;
        try
        {
            if (ground.getCharacter(k)->getCharacterGender() == SEX::MALE)
            {
                character = new MaleCharacter(*static_cast<MaleCharacter*>(ground.getCharacter(k)));
            }
            else
            {
                character = new FemaleCharacter(*static_cast<FemaleCharacter*>(ground.getCharacter(k)));
            }
            this->addCharacter(character);
        }
        catch(OutOfRangeSuperior& e)
        {
            e.setValueOutOfRange(k, ground.vector_character.size()) ;
            throw ; 
        }
        
    }
}

/**
 * \fn Ground::~Ground()
 * \brief Destructeur de la classe Ground
 */
Ground::~Ground()
{
    for (auto &character : vector_character)
    {
        delete character;
    }
}

/**
 * \fn unsigned int Ground::getGroundId() const noexcept
 * \brief Getteur sur l'identifiant unique du terrain
 * \return Identifiant unique du terrain
 */
unsigned int Ground::getGroundId() const noexcept
{
    return ground_id;
}

/**
 * \fn GROUND_TYPE Ground::getGroundType() const noexcept
 * \brief Getteur sur le type de terrain
 * \return Type de terrain
 */
GROUND_TYPE Ground::getGroundType() const noexcept
{
    return ground_type;
}

/**
 * \fn unsigned int Ground::getVectorSize() const noexcept
 * \brief Getteur sur le nombre de personnage sur le terrain
 * \return La taille du vecteur
 */
unsigned int Ground::getVectorSize() const noexcept
{
    return vector_character.size();
}

/**
 * \fn StructCoordinates Ground::getPosition(int column_number) const
 * \brief Getteur sur la position actuelle du terrain avec des coordonnees (x,y)
 * \return La position du terrain sur la carte
 */
StructCoordinates Ground::getPosition(int column_number) const
{
    if (column_number < 0)
    {
        throw InvalidColumnNumber(column_number) ; 
    }
    return StructCoordinates(ground_id / column_number, ground_id % column_number);
}
/**
 * \fn void Ground::addCharacter(Character *new_worker)
 * \brief Methode qui ajoute un personnage sur un terrain
 * \param new_worker Personnage que l'on veut ajouter au vecteur
 */
void Ground::addCharacter(Character *new_worker)
{
    try
    {
        /* On verifie que l'allocation d'un personnage est possible */
        vector_character.push_back(new_worker);
    }
    catch (const std::bad_alloc &e)
    {
        throw ;
    }
}

/**
 * \fn void Ground::removeCharacter(const unsigned int index)
 * \brief Methode qui retire un personnage d'un terrain
 * \param index Indice dans le vecteur
 */
void Ground::removeCharacter(const unsigned int index)
{
    if (index >= vector_character.size())
    {
        throw OutOfRangeSuperior(vector_character.size(), index);
    }

    vector_character.erase(vector_character.begin() + index);
}

/**
 * \fn Character *Ground::getCharacter(const unsigned int index)
 * \brief Getteur sur un personnage
 * \param index Indice dans le vecteur
 * \return Personnage a l'indice index
 */
Character *Ground::getCharacter(const unsigned int index) const
{
    if (index >= vector_character.size())
    {
        throw OutOfRangeSuperior(index, vector_character.size() - 1);
    }

    return vector_character[index];
}

/**
 * \fn bool Ground::operator==(const Ground &ground)
 * \brief Surchage de l'operateur d'egalite. Le test d'egaliter se fait sur l'identfiant unique du terrain
 * \param ground Terrain que l'on veut comparer
 * \return Vrai si les terrains sont similaires, faux sinon
 */
bool Ground::operator==(const Ground &ground)
{
    return ground_id == ground.ground_id ? true : false;
}

/**
 * \fn void Ground::resetGroundNumber() noexcept
 * \brief Remet a 0 la variable statique du nombre de terrain genere
 */
void Ground::resetGroundNumber() noexcept
{
    ground_number = 0;
}

/**
 * \fn void Ground::display(std::ostream &os) const noexcept
 * \brief Affichage d'un terrain. Cette methode est virtuel, dans le but d'etre redefini dans les classes filles
 * \param os Flux ou l'on va afficher le terrain
 */
void Ground::display(std::ostream &os) const noexcept
{
    os << ". ";
}
