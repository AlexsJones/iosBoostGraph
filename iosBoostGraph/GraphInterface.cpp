//
//  GraphInterface.cpp
//  iosBoostGraph
//
//  Created by Alex Jones on 06/04/2016.
//  Copyright © 2016 Alex Jones. All rights reserved.
//

#include <stdio.h>
#include "GraphInterface.hpp"

#include <boost/graph/graphviz.hpp>
#include <boost/graph/topology.hpp>
#include <boost/graph/fruchterman_reingold.hpp>
#include <boost/graph/random_layout.hpp>
//Including custom types in this file, hidden out of the header
#include "cwGraphTypes.cpp"
#include <boost/graph/topology.hpp>
#include <boost/random.hpp>
#include <unordered_map>
#include <boost/variant/get.hpp>
using namespace boost;

std::shared_ptr<CXXProcessedNodeList> GraphInterface::ProcessGraph(CXXComposeNodeList *c) {
    
    boost::dynamic_properties dp;
    
    AdGraph g;
    
    //Initially let's create the vertices
    std::vector<std::shared_ptr<CXXComposedNode>>::iterator it;
    
    std::unordered_map<std::string, vertex_t> vertices;
    
    for(it = c->nodes.begin(); it != c->nodes.end(); ++it) {
        
        std::shared_ptr<CXXComposedNode> node = *it;
        
        vertex_t v1 = boost::add_vertex(g);
        
        g[v1].name = node->guid;
        
        vertices[node->guid] = v1;
    }
    
    //Now all vertices are loaded with their guids we can reloop the list and pull them out to find edges
    
    for(it = c->nodes.begin(); it != c->nodes.end(); ++it) {
        
        std::shared_ptr<CXXComposedNode> node = *it;
        
        std::vector<std::string>::iterator sit;
        
        for(sit = node->pointsTo.begin(); sit != node->pointsTo.end(); ++sit ) {
            
            std::string str = *sit;
            
            boost::add_edge(vertices[node->guid], vertices[str],g);
        }
    }
    
    
    //Add dynamic property node_id
    dp.property("node_id", get(&Vertex::name, g));
    
    //Create topology map
    using Topology = boost::square_topology<boost::mt19937>;

    using Position = Topology::point_type;
    
    std::vector<Position> positions(num_vertices(g));
    
    square_topology<boost::mt19937> topology;
    
    typedef rectangle_topology<> topology_type;
    
    typedef topology_type::point_type point_type;
    
    minstd_rand gen;
    
    topology_type topo(gen,0,0,c->width, c->height);
    
    /*
     This is still a work in progress but essentially we are creating a topology and position map
     Feeding in our verticies into the graph layouts then using the processed positions on the other side
     http://www.boost.org/doc/libs/1%5F38%5F0/libs/graph/doc/fruchterman%5Freingold.html
     defined: http://www.boost.org/doc/libs/1%5F38%5F0/boost/graph/fruchterman_reingold.hpp
     */
    
    
    random_graph_layout(g,
                        make_iterator_property_map(positions.begin(), boost::identity_property_map{}),
                        topo);
    
    fruchterman_reingold_force_directed_layout(
                                               g,
                                               make_iterator_property_map(positions.begin(), boost::identity_property_map{}),
                                               topo,
                                               attractive_force(AttractionF())
                                               );
    
    std::stringstream *s = new std::stringstream();
    
    boost::write_graphviz_dp(*s, g, dp, std::string("node_id"));
    
    std::cout << s->str() << std::endl;
    
    graph_traits<AdGraph>::vertex_iterator vi, vi_end;
    
    std::shared_ptr<CXXProcessedNodeList> processedList = std::make_shared<CXXProcessedNodeList>();
    
    for (boost::tie(vi, vi_end) = boost::vertices(g); vi != vi_end; ++vi) {
        
        std::cout << get(&Vertex::name, g, *vi) << '\t' << positions[*vi][0] << '\t' << positions[*vi][1] << std::endl;
        
        std::shared_ptr<CXXProcessedNode> node = std::make_shared<CXXProcessedNode>();
        
        node->guid = get(&Vertex::name, g, *vi);
        
        node->coord.x = positions[*vi][0];
        
        node->coord.y = positions[*vi][1];
        
        processedList->nodes.push_back(node);
    }
    
    processedList->width = c->width;
    
    processedList->height = c->height;
    
    return processedList;
}
