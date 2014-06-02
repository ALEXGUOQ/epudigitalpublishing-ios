##	EPUDigitalPublishing

A simple application for include EPU service inside your applications.

##	How to install EPU framework inside your application
You can include EPU inside your application only if your app is UINavigationcontroller based. EPU view is pushed inside your navigation controller stack.

1. Copy file epuFramework.framework in your project
2. Copy folder res in your project

3. Include framework in your view controller
		import <epuFramework/EpuViewController.h>
		import <epuFramework/EPUengine.h>

4. Init EPU in your code
	// 	Init engine (EPU instance is shared across your application)
	//
	EPUengine* sharedSingleton = [EPUengine sharedInstance];
	// 	Set your apicode
	//
	sharedSingleton.apicode = @“xxxxxxxx”;
	//	Set book by id
  //
	sharedSingleton.book = @"73";
	//	Set edition by id
	//
	sharedSingleton.edition = @"1361";

5. Framework to add to your project:

		MessageUI
		QuartzCore
		AVFoundation
		CoreMedia
		MobileCoreService
		Security
		SystemConfiguration
		CoreData
		libsqlite3.0
		epuFramework
		CFNetwork
		UIKit
		Foundation
		CoreGraphics

Your EPU book is linked!

## EPU Proprieties:
You can set this proprieties:

 NSString  server
 NSString  book
 NSString  edition
 NSString  apicode
 NSString  agent
 NSString  subscriptionTransactionId
 NSString  searchForText
 NSString  hMode (DOUBLE) DOUBLE/SINGLE
 NSString  maxZoom (3.0) 0.0->5.0
 int perc (10) recommended values: 10->20
 int epuLog (0) 0/1 if 1 show Log for EPU


##	EPU Methods:

	###	-(NSMutableDictionary *)getDataFromServer:(bool)online;
		Return list of available editions for your book.
		Return NSMutableDictionary for keys: editions , 		subscriptions.
	- Key editions contains an Array of dictionary with list of editions for your book.
	- Subscriptions key contains an array for your book subscriptions.

	###	-(void)openEPUView:(UINavigationController *)nc animated:(bool)animated;
	Open EPU view pushing view in your UINavigationcontroller.


##	Returned messages:

EPU uses NSNotificationCenter for send messages to your app, you can get messages for know current page, share elements on social network, add favorites to your list, get current download status for edition. 

In your application you can get messages in this way: 

	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(manageEPUMessage:) name:@"EPU_message" object:nil];

	-(void)manageEPUMessage:(NSMutableDictionary *)dic {
    NSLog(@"Message %@", dic);
	}

Here is EPU Messages: (returned NSMutableDictionary)

	- Current page
		edition
		page	
	- Add favourite
		edition
		page
		pageName	
	- Shared element	
		edition
		image
		EPUUrlSharer
		text
	- Current download ratio	
		edition
		ratio