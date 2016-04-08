//
//  iosBoostGraph.m
//  iosBoostGraph
//
//  Created by Alex Jones on 05/04/2016.
//  Copyright © 2016 Alex Jones. All rights reserved.
//

#import "iosBoostGraph.h"
#import "GraphInterface.hpp"

@implementation iosBoostGraph

-(NSString* )test {

    GraphInterface g;
    
    auto s = g.TestGraphWrite();
    
    return [NSString stringWithFormat:@"%s",s.c_str()];
}

-(bool)testRead {
    
    GraphInterface g;

    return g.TestGraphReadFromString("digraph { graph [name=\"graphname\"]  a  c e [mass = 6.66] }");
}


@end
