//
//  home.h
//  EPUapi
//
//  Created by Simone Moreschi on 29/05/14.
//
//

#import <UIKit/UIKit.h>
#import <epuFramework/EpuViewController.h>
#import <epuFramework/EPUengine.h>
#import "EPUapiAppDelegate.h"

@interface home : UIViewController <UITableViewDataSource, UITableViewDelegate> {

    EPUengine *sharedSingleton;
    
    NSMutableArray *editions;
    IBOutlet UITableView *tbl;
    IBOutlet UITableViewCell *cellEditionsList;
}

-(IBAction)openEPU;

@end