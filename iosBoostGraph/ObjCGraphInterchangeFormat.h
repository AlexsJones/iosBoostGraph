//
//  GraphInterchangeFormat.h
//  iosBoostGraph
//
//  Created by Alex Jones on 11/04/2016.
//  Copyright © 2016 Alex Jones. All rights reserved.
//

#ifndef GraphInterchangeFormat_h
#define GraphInterchangeFormat_h


@interface ComposedNode : NSObject {
    
    NSString *guid;
    CGPoint *oord;
    NSArray *pointsTo;
    
};

@property NSString *guid;
@property CGPoint coord;
@property NSArray *pointsTo;

@end

@implementation ComposedNode

@synthesize guid;
@synthesize coord;
@synthesize pointsTo;
@end
@interface ComposedNodeList : NSObject {
    
    CGFloat width;
    CGFloat height;
    NSMutableArray *composedList;
    
};

@property CGFloat width;
@property CGFloat height;
@property NSMutableArray *composedList;

-(void)print;
@end

@implementation ComposedNodeList

@synthesize composedList;
@synthesize width;
@synthesize height;
-(void)print {
    
    NSLog(@"------------------------\n");
    
    for(ComposedNode *comp in composedList) {
        
        NSLog(@"-\n");
        NSLog(@"Node : %@",comp.guid);
        NSLog(@"Coords: %f %f",comp.coord.x, comp.coord.y);
        
        for (NSString *s in comp.pointsTo) {
            
            NSLog(@"---> %@",s);
            
        }
        
        NSLog(@"-\n");
        
    }
    NSLog(@"------------------------\n");
    
}
@end

@interface ProcessedNode : NSObject {
    
    NSString *guid;
    CGPoint coord;
    
};

@property NSString *guid;
@property CGPoint coord;

@end

@implementation ProcessedNode

@synthesize guid;
@synthesize coord;
@end

@interface ProcessedNodeList : NSObject {
    CGFloat width;
    CGFloat height;
    NSMutableArray *processedList;
}

@property CGFloat width;
@property CGFloat height;
@property NSMutableArray *processedList;

@end

@implementation ProcessedNodeList

@synthesize processedList;
@synthesize width;
@synthesize height;
@end

#endif /* GraphInterchangeFormat_h */
