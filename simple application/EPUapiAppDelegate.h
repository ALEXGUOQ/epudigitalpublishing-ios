//
//  EPUapiAppDelegate.h
//  EPU
//
//  Created by Simone Moreschi on 28/05/2014.
//  Copyright 2014 __Celeweb__. All rights reserved.
//
//  V1.0

#import <UIKit/UIKit.h>
#import "Reachability.h"
#import "home.h"

@interface EPUapiAppDelegate : NSObject <UIApplicationDelegate, NSXMLParserDelegate> {

    Reachability* hostReach;
    Reachability* internetReach;
    Reachability* wifiReach;

    bool connectivity;
}

-(void)manageEPUMessage:(NSMutableDictionary *)dic;

//  Proprietà
@property (nonatomic, strong) IBOutlet UIWindow *window;
//@property (nonatomic, strong) navcontroller *navigationController;
@property(nonatomic)bool connectivity;

@end