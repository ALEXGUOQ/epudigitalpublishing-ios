//
//  caroselloViewController.h
//  jtech-arc
//
//  Created by Simone Moreschi on 25/10/13.
//  Copyright (c) 2013 Simone Moreschi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "iCarousel.h"
#import "EPUengine.h"
#import "AsyncImageView.h"
#import <MessageUI/MessageUI.h>
#import <MessageUI/MFMailComposeViewController.h>

@interface caroselloViewController : UIViewController <MFMailComposeViewControllerDelegate, iCarouselDataSource, iCarouselDelegate, UIScrollViewDelegate> {

    IBOutlet UIButton *indietro;
    IBOutlet UIView *sopra;
    IBOutlet UIView *sotto;
    IBOutlet UILabel *contatore;
    IBOutlet UIButton *btnSuccessivo;
    IBOutlet UIButton *btnPrecedente;
    NSString *screenName;
    
    NSMutableArray *foto;
    
    int showIndex;
    int curIndex;
    
}

@property(nonatomic, strong) IBOutlet iCarousel *carosello;
@property(nonatomic, strong) NSMutableArray *foto;
@property(nonatomic, strong)NSString *screenName;

@end