//
//  iosBoostGraph.h
//  iosBoostGraph
//
//  Created by Alex Jones on 05/04/2016.
//  Copyright © 2016 Alex Jones. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "iosBoostGraphProtocol.h"

@interface iosBoostGraph : NSObject <iosBoostGraphProtocol>

-(NSString * )testWrite;

-(bool)testRead;

@end
