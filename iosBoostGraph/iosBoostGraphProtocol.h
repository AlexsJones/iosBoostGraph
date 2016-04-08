//
//  iosBoostGraphProtocol.h
//  iosBoostGraph
//
//  Created by Alex Jones on 05/04/2016.
//  Copyright © 2016 Alex Jones. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol iosBoostGraphProtocol <NSObject>

@optional

-(NSString *)test;

-(void) writeGraph:(NSString *)fromString;

-(void) readGraph;

@end
