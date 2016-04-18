//
//  iosBoostGraph.m
//  iosBoostGraph
//
//  Created by Alex Jones on 05/04/2016.
//  Copyright © 2016 Alex Jones. All rights reserved.
//

#import "iosBoostGraph.h"
#import "GraphInterface.hpp"
#import "CXXGraphicInterchangeFormat.h"

@implementation iosBoostGraph

-(ProcessedNodeList*)processGraph:(ComposedNodeList *)nodelist withPositionMapHeight:(CGFloat)height withPositionMapWidth:(CGFloat)width {
    
    CXXComposeNodeList cnl;
    
    cnl.height = height;
    cnl.width = width;
    
    for(ComposedNode *c in nodelist.composedList) {
     
        std::shared_ptr<CXXComposedNode> cxxNode = std::make_shared<CXXComposedNode>();
        
        cxxNode->guid = std::string(c.guid.cString);
        
        CXXSimplifiedPoint p;
        p.x = c.coord.x;
        p.y = c.coord.y;
        
        cxxNode->coord = p;
        
        std::vector<std::string> v;
        
        for(NSString *s in c.pointsTo) {
            
            v.push_back(std::string(s.cString));
        }
        
        cxxNode->pointsTo = v;
        
        cnl.nodes.insert(cnl.nodes.end(), cxxNode);
    }
    cnl.print();
    
    
    GraphInterface g;
    
    std::shared_ptr<CXXProcessedNodeList> processedList = g.ProcessGraph(&cnl);
    
    //Convert back into an ObjC++ type list
    
    ProcessedNodeList *processedNodeList = [[ProcessedNodeList alloc] init];
    
    processedNodeList.width = processedList->width;
    
    processedNodeList.height = processedList->height;
    
    processedNodeList.processedList = [[NSMutableArray alloc]init];
    
    std::vector<std::shared_ptr<CXXProcessedNode>>::iterator it;
    
    for(it = processedList->nodes.begin(); it != processedList->nodes.end(); ++it) {
        
        std::shared_ptr<CXXProcessedNode> pn = *it;
        
        ProcessedNode *pnode = [[ProcessedNode alloc] init];
        
        pnode.guid = [NSString stringWithFormat:@"%s", pn->guid.c_str()];
        
        pnode.coord = CGPointMake(pn->coord.x,pn->coord.y);
        
        [processedNodeList.processedList addObject:pnode];
    }
    
    return processedNodeList;
}

@end
