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
#include "CXXGraphicInterchangeFormat.h"

typedef enum GraphInterfaceResponseStatus {
    OKAY,
    FAILED,
    MALFORMED
}GraphInterfaceResponseStatus;

class GraphInterface {
 
public:
    
    std::shared_ptr<CXXProcessedNodeList> ProcessGraph(CXXComposeNodeList *c);

};
#endif /* GraphInterface_hpp */
