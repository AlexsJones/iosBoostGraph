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
//Including custom types in this file, hidden out of the header
#include "cwGraphTypes.cpp"

std::string GraphInterface::TestGraphWrite() {

    boost::dynamic_properties dp;
    
    AdGraph g;
    
    vertex_t v1 = boost::add_vertex(g);
    
    vertex_t v2 = boost::add_vertex(g);
    
    vertex_t v3 = boost::add_vertex(g);
    
    boost::add_edge(v1, v2, g);
    
    boost::add_edge(v1, v3, g);
    
    g[v1].foo = 10;
    g[v1].id = "node_v1";
    
    g[v2].shape = "house";
    g[v2].id = "node_v2";
    
    g[v3].id = "node_v3";
    g[v3].shape = "rectangle";
    
    dp.property("shape", get(&VertexP::shape, g));
    
    dp.property("id", get(&VertexP::id, g));
    
    std::stringstream *s = new std::stringstream();
    
    boost::write_graphviz_dp(*s, g, dp, std::string("id"));

    g.clear();
    
    std::string str(s->str());
    
    delete s;
    
    return str;
}

bool GraphInterface::TestGraphReadFromString(std::string s) {
    
    // Construct an empty graph and prepare the dynamic_property_maps.
    graph_t graph(0);
    boost::dynamic_properties dp;
    
    boost::property_map<graph_t, boost::vertex_name_t>::type name =
    get(boost::vertex_name, graph);
    dp.property("node_id",name);
    
    boost::property_map<graph_t, boost::vertex_color_t>::type mass =
    get(boost::vertex_color, graph);
    dp.property("mass",mass);
    
    boost::property_map<graph_t, boost::edge_weight_t>::type weight =
    get(boost::edge_weight, graph);
    dp.property("weight",weight);
    
    // Use ref_property_map to turn a graph property into a property map
    boost::ref_property_map<graph_t*,std::string>
    gname(get_property(graph,boost::graph_name));
    dp.property("name",gname);
    
    // Sample graph as an std::istream;
    std::istringstream gvgraph(s.c_str());
    
    bool status = false;
    try {
        status = read_graphviz(gvgraph,graph,dp,"node_id");
    }catch(std::exception e) {
        
        std::cout << e.what() << std::endl;
    }
    
    return status;
}
