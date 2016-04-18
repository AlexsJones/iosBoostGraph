//
//  CXXGraphicInterchangeFormat.h
//  iosBoostGraph
//
//  Created by Alex Jones on 11/04/2016.
//  Copyright © 2016 Alex Jones. All rights reserved.
//

#ifndef CXXGraphicInterchangeFormat_h
#define CXXGraphicInterchangeFormat_h
#import <vector>

class CXXSimplifiedPoint {
public:
    float x;
    float y;
};

class CXXComposedNode {

public:
    std::string guid;
    
    CXXSimplifiedPoint coord;
    
    std::vector<std::string> pointsTo;
};

class CXXProcessedNode {
    
public:
    std::string guid;
    
    CXXSimplifiedPoint coord;

};

class CXXProcessedNodeList {
    
public:
    std::vector<std::shared_ptr<CXXProcessedNode>> nodes;
    
    float height;
    
    float width;
};

class CXXComposeNodeList {
    
public:
    
    std::vector<std::shared_ptr<CXXComposedNode>> nodes;

    float height;
    
    float width;
    
    void print() {
      
        std::vector<std::shared_ptr<CXXComposedNode>>::iterator it;
        
        std::cout << "------------------------\n";
        
        for(it = nodes.begin(); it != nodes.end(); ++it) {
        
            std::shared_ptr<CXXComposedNode> current = *it;
            
            std::cout << "-\n";
            
            std::cout << "Node : " << current->guid.c_str() << std::endl;
       
            std::cout << "Coords:" << current->coord.x << " : " << current->coord.y << std::endl;

            std::vector<std::string>::iterator sit;
            
            for(sit = current->pointsTo.begin(); sit != current->pointsTo.end(); ++sit) {
                
                std::string s = *sit;
               
                std::cout << "---> " << s.c_str() << std::endl;

            }
            
            std::cout << "-\n";
            
        }
        
        std::cout << "------------------------\n";
    };
    
};

#endif /* CXXGraphicInterchangeFormat_h */
