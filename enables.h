//
// Created by Kirill Khlopko.
//

#define POST
#define NAM
#define SORTING
#define GRAPH

#ifdef POST

#include "post/Machine.h"

#endif

#ifdef NAM

#include "nam/NMA.h"
#include "nam/Substitution.h"

#endif

#ifdef SORTING

#include "sorting/sorting.h"
#include "sorting/sorting.cpp"

#endif

#ifdef GRAPH

#include "graph/model.h"
#include "graph/graph.h"

#endif
