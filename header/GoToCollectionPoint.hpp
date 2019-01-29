#ifndef GOTOCOLLECTIONPOINT_HPP
#define GOTOCOLLECTIONPOINT_HPP


#include "State.hpp"



class GoToCollectionPoint : public State
{
    public:

        GoToCollectionPoint();
        ~GoToCollectionPoint();
        void run(Ground *, Character *);
};

#endif
