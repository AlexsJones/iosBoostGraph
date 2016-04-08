//
//  GraphInterface.hpp
//  iosBoostGraph
//
//  Created by Alex Jones on 05/04/2016.
//  Copyright © 2016 Alex Jones. All rights reserved.
//

#ifndef GraphInterface_hpp
#define GraphInterface_hpp
#import <iostream>
#include <stdio.h>

class GraphInterface {
 
public:
    
    std::string TestGraphWrite(void);
    
    bool TestGraphReadFromString(std::string s);
    
//    void WriteGraph(std::ostream& out, const Graph& g,
//                    const dynamic_properties& dp);
};
#endif /* GraphInterface_hpp */
