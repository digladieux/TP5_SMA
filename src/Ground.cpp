/**
 * \file Ground.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian ()
 * \brief Fichier d'implementation d'un terrain
 * \date 2018-12-06
 */

#include "../header/Ground.hpp"
#include <iostream>
#include <exception>

/**
 * \brief Met la variable statique du nombre de terrain genere a 0 ;
 *
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

/**
 * \brief Constructeur de copie de la classe Ground
 * \param ground Le terrain que l'on veut copier
 */
Ground::Ground(const Ground *ground)
{
    ground_id = ground->ground_id;
    ground_type = ground->ground_type;
    try
    {
        /* On verifie que l'allocation des personnages est possible */
        vector_character.resize(ground->vector_character.size());
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "BAD_ALLOCATION" << std::endl;
        throw e;
    }

    /* On copie tous les personnages sur le terrain */
    for (unsigned int i = 0; i < vector_character.size(); i++)
    {
        vector_character[i] = ground->vector_character[i];
    }
}

/**
 * \fn Ground::~Ground()
 * \brief Destructeur de la classe Ground
 */
Ground::~Ground()
{
    Character *character;
    while (vector_character.size() != 0)
    {
        character = vector_character[0];
        vector_character.erase(vector_character.begin()); /* On supprime le personnage dans le vecteur */
        delete character;                                 /* On libere la memoire de ce personnage */
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
        std::cerr << "VECTOR_TOO_HIGH" << std::endl;
        throw e;
    }
}

/**
 * \fn void Ground::removeCharacter(const unsigned int index)
 * \brief Methode qui retire un personnage d'un terrain
 * \param index Indice dans le vecteur
 */
void Ground::removeCharacter(const unsigned int index)
{
    if (((int)index < 0) || (index >= vector_character.size()))
    {
        /* On verifie que l'index est compris dans les bornes du vecteur */
        std::cerr << "ERROR-  [0;" << vector_character.size() - 1 << "], INDEX = " << index << std::endl;
        throw std::out_of_range("OUT_OF_RANGE_EXCEPTION");
    }

    Character *character = vector_character[index];
    vector_character.erase(vector_character.begin() + index);
    delete character;
}

/**
 * \fn Character *Ground::getCharacter(const unsigned int index)
 * \brief Getteur sur un personnage
 * \param index Indice dans le vecteur
 * \return Personnage
 */
Character *Ground::getCharacter(const unsigned int index)
{
    if (((int)index < 0) || (index >= vector_character.size()))
    {
        /* On verifie que l'index est compris dans les bornes du vecteur */
        std::cerr << "ERROR - [0;" << vector_character.size() - 1 << "], INDEX = " << index << std::endl;
        throw std::out_of_range("OUT_OF_RANGE_EXCEPTION");
    }

    return vector_character[index];
}

/**
 * \fn bool Ground::operator==(const Ground &ground)
 * \brief Surchage de l'operateur ==. Le test d'egaliter se fait sur l'identfiant unique du terrain
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
