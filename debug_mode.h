//
// Created by ruslan on 5/11/17.
//

#ifndef LB_3_HOUSEPLANT_DEBUG_MODE_H
#define LB_3_HOUSEPLANT_DEBUG_MODE_H

#include <iostream>

//#define DEBUG_ON

#ifdef DEBUG_ON
#define DEBUG(x) std::cout << x << "\n"
#else
#define DEBUG(x) do {} while(0)
#endif

#endif //LB_3_HOUSEPLANT_DEBUG_MODE_H
