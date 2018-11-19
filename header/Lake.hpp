#ifndef LAKE_HPP
#define LAKE_HPP

#include "CollectionPoint.hpp"

class Lake : public CollectionPoint
{
    public:
      Lake(const unsigned int fish_nb = 1000);
      ~Lake();

};
#endif
