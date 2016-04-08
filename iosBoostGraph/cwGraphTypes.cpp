//
//  cwGraphTypes.h
//  iosBoostGraph
//
//  Created by Alex Jones on 08/04/2016.
//  Copyright © 2016 Alex Jones. All rights reserved.
//

#ifndef cwGraphTypes_h
#define cwGraphTypes_h
#include <boost/graph/graphviz.hpp>

// Properties-----
typedef boost::property < boost::vertex_name_t,std::string, boost::property < boost::vertex_color_t, float > > vertex_p;

typedef boost::property < boost::edge_weight_t, double > edge_p;

typedef boost::property < boost::graph_name_t, std::string > graph_p;
///---------------

//Custom graph properties
struct VertexP { int foo; std::string shape; std::string id;};

struct EdgeP   { uint64_t nse; };
//----------------

//Graph Types-----
typedef boost::adjacency_list < boost::vecS, boost::vecS, boost::directedS,
vertex_p, edge_p, graph_p > graph_t;

typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, VertexP, EdgeP> AdGraph;
//----------------

//Graph traits----
typedef boost::graph_traits<AdGraph>::vertex_descriptor vertex_t;

typedef boost::graph_traits<AdGraph>::edge_descriptor edge_t;
//----------------
#endif /* cwGraphTypes_h */
