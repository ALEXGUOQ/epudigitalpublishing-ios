//
//  EPUapiAppDelegate.m
//  EPU
//
//  Created by Simone Moreschi on 28/05/2014.
//  Copyright 2014 __Celeweb__. All rights reserved.
//
//  V1.0

#import "EPUapiAppDelegate.h"

@implementation EPUapiAppDelegate

@synthesize window = _window;
@synthesize connectivity;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    //  Lancia osservatore connettività
    [[NSNotificationCenter defaultCenter] addObserver: self selector: @selector(reachabilityChanged:) name: kReachabilityChangedNotification object: nil];
	hostReach = [Reachability reachabilityWithHostName: @"epu.celewebdev.co.uk"];
    [hostReach startNotifier];
    
    Reachability *networkReachability = [Reachability reachabilityForInternetConnection];
    NetworkStatus networkStatus = [networkReachability currentReachabilityStatus];
    if (networkStatus != NotReachable) {
        self.connectivity = TRUE;
    } else {
        self.connectivity = FALSE;
    }
    
    home *hom = [[home alloc] init];

    UINavigationController *nc = [[UINavigationController alloc] initWithRootViewController:hom];
    
    [self.window setRootViewController:nc];
    [self.window makeKeyAndVisible];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(manageEPUMessage:) name:@"EPU_message" object:nil];

    return YES;
}


-(void)manageEPUMessage:(NSMutableDictionary *)dic {
    NSLog(@"Ricevuto %@", dic);
}



- (void)applicationWillResignActive:(UIApplication *)application {}

- (void)applicationDidEnterBackground:(UIApplication *)application {}

- (void)applicationWillEnterForeground:(UIApplication *)application {}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    Reachability *networkReachability = [Reachability reachabilityForInternetConnection];
    NetworkStatus networkStatus = [networkReachability currentReachabilityStatus];
    if (networkStatus != NotReachable) {
        self.connectivity = TRUE;
    } else {
        self.connectivity = FALSE;
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"restart" object:nil];
}

- (void)applicationWillTerminate:(UIApplication *)application {}


//
//	Network
- (void) reachabilityChanged: (NSNotification* )note {
    Reachability* curReach = [note object];
    NSParameterAssert([curReach isKindOfClass: [Reachability class]]);
    [self updateInterfaceWithReachability: curReach];
}

- (void) updateInterfaceWithReachability: (Reachability*) curReach {
    if(curReach == hostReach)
    {
        if ([curReach currentReachabilityStatus] == NotReachable) {
			self.connectivity = FALSE;
		} else {
            if (self.connectivity == false) {
                [[NSNotificationCenter defaultCenter] postNotificationName:@"restart" object:nil];
            }
            self.connectivity = TRUE;
		}
		
	}
}

@end