//
//  multimedia.h
//  Clorofilla Lover
//
//  Created by Simone Moreschi on 16/11/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncImageView.h"
#import "EPUengine.h"

@interface multimedia : UIViewController {
    
    int intPag, intIdx, pag;
    NSMutableArray *punti;
    NSString *screenName;
    
    IBOutlet UIWebView *multiWeb;
    IBOutlet UIPageControl *pc;
    IBOutlet UIScrollView *multiGallery;
    IBOutlet UIActivityIndicatorView *act;
    
}

-(void)scaricaImmagineBackground:(NSArray *)dati;
-(void)caricaImmagine:(int)indice;
-(IBAction)ritorna:(id)sender;
-(void)mostra;

@property(nonatomic, strong)NSString *screenName;

@end