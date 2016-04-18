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
/*
 adjacency_list<OutEdgeList, VertexList, Directed,
 VertexProperties, EdgeProperties,
 GraphProperties, EdgeList>
 */

// Fruchterman Reingold attraction force-----
struct AttractionF {
    template <typename EdgeDescriptor, typename Graph>
    double operator()(EdgeDescriptor /*ed*/, double k, double d, Graph const& /*g*/) const {
        //std::cout << "DEBUG af('" << g[source(ed, g)].name << " -> " << g[target(ed, g)].name << "; k:" << k << "; d:" << d << ")\n";
        return (d*d/k);
    }
};

///---------------

//Custom graph properties
struct Vertex { std::string name; };

//----------------

//Graph Types-----
//typedef boost::adjacency_list < boost::vecS, boost::vecS, boost::directedS,
//vertex_p, edge_p, graph_p > graph_t;

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,Vertex> AdGraph;
//----------------

//Graph traits----
typedef boost::graph_traits<AdGraph>::vertex_descriptor vertex_t;

typedef boost::graph_traits<AdGraph>::edge_descriptor edge_t;
//----------------
#endif /* cwGraphTypes_h */
