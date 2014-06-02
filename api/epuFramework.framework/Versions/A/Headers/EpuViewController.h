//
//  EpuViewController.h
//  Clorofilla Lover
//
//  Created by Simone Moreschi on 25/03/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "EPUengine.h"
#import <MessageUI/MessageUI.h>
#import "AsyncImageView.h"
#import "multimedia.h"
#import "iCarousel.h"
#import "caroselloViewController.h"

@class preferiti;

@interface EpuViewController : UIViewController <UIScrollViewDelegate, UIWebViewDelegate, MFMailComposeViewControllerDelegate, NSXMLParserDelegate, UITableViewDataSource, UITableViewDelegate, UIPopoverControllerDelegate, iCarouselDataSource, iCarouselDelegate> {

    UIScrollView *scrolla;
    CATiledLayer *tiledLayer;
    CATiledLayer *tiledLayer2;
    UIView *myVista;

    //  Main view
    IBOutlet UILabel *lblPercentuale;
    IBOutlet UITableViewCell *tvCell;
    IBOutlet UIView *vistaAcquista;
    IBOutlet UILabel *lblVistaAcquista;
    IBOutlet UIImageView *immVistaAcquista;
    IBOutlet UIButton *btnVistaAcquista;
    IBOutlet UIScrollView *mainScrolla;
    IBOutlet UIButton *btnShowMultimedia;
    IBOutlet UIImageView *imgPreferitoAggiunto;
    
    //  Cassettino
    IBOutlet UIImageView *imgFumetto;
    IBOutlet UIView *cassetto;
    IBOutlet UILabel *lblLoader;
    IBOutlet UIButton *btnCorrelato;
    IBOutlet UIButton *btnAsso;
    IBOutlet UIButton *elemButton;
    IBOutlet UILabel *lblContatoreArticoli;
    IBOutlet UIScrollView *carosello;
    IBOutlet UIButton *btnReturn;
    IBOutlet UIButton *btnCorPrecedente;
    IBOutlet UIButton *btnGoIndietro;

    UIProgressView *prog;
    
    UITableView *tblAssociati;
    UIPopoverController *pop;
    UIViewController *popoverContent;
    
    UILabel *lblNumeroPagina;
    
    preferiti *preferito;

    int curPag;
    int blocco;
    int imgWidth;
    int imgHeight;
    int altezzaCassetto;
    int completo;
    int precTag;
    int precPag;
    int curMostra;
    int intPag;
    int intIdx;
    int wPag;
    int hPag;
    int wMin;
    int hMin;
    int wMinCass;
    int hMinCass;
    int pag;
    int mostraMultimedia;
    int precCor;
    int totVisibili;
    int showGost;
    int wCcarosello;
    int nascosto;

    
    UIButton *scaricaButton;
    UIButton *annullaButton;
    UILabel *labPercentuale;
    
    bool cassettoAperto;
    bool bloccoRotazione;

    NSTimer *timer;

    UIButton *elemento;

    // parser XML
	NSXMLParser *rssParser;

	// elenco degli elementi letti dal feed
	NSMutableArray *elencoFeed;
    NSMutableArray *elenco_multi;
    NSMutableArray *punti;
    NSMutableArray *memoCarosello;
    NSMutableArray *memoGost;
    
	//variabile temporanea per ogni elemento
	NSMutableDictionary *item;
    NSMutableDictionary *item_multi;
    NSMutableDictionary *memoHL;
    
    NSString *currentElement;
    NSString *orientation;
    NSString *filePagine;
    NSString *elencoFiles;
    
	NSMutableString *strPk;
    NSMutableString *strPagina;
    NSMutableString *strTipo;
    NSMutableString *strMin;
    NSMutableString *strX;
    NSMutableString *strY;
    NSMutableString *strW;
    NSMutableString *strH;
    NSMutableString *strData;
    NSMutableString *strFoto;
    NSMutableString *formatoPagina;
    NSMutableString *formatoMiniatura;

    UIScrollView *scrollCorrelati;
    
    int realhPag, realWPag, limitW, limitH;
    
    NSString *globShareUrl, *globShareImg, *globShareTesto;
}

-(CGPoint)adjustTouch:(CGPoint)aTouch forOrientation:(UIInterfaceOrientation)aOrientation scro:(UIScrollView *)scr;
-(void)vaiPubblicaFB;
-(void)pubblicaFB:(int)pag idx:(int)idx;
-(void)systemGoToPage:(int)tid;
-(int)trovaNumeroProdottiCarrello;
-(IBAction)indietro;
-(IBAction)vaiACorrPrecedente;
-(int)percentualeAttuale;
-(void)caricaImmagine:(int)indice elem:(int)idxElemento;
-(void)parseXMLFileAtURL:(NSString *)URL;
-(void)pulisciTutto;
-(IBAction)invito:(NSString *)mailTo;
-(IBAction)mostraVistaAcquista;
-(IBAction)btnAcquistaNumero;
-(int)getScaleMulti:(int)valore tipo:(int)tipo porta:(int)porta;
-(void)scaricaPaginaPdf:(NSString *)nomePagina;
-(void)disegnaScriviTesti;
-(void)disegnaCarosello;
-(IBAction)apriChiudiCassetto;
-(void)caricaVincent;
-(void)disegnaCassetto;
-(void)disegnaPagina;
-(void)home;
-(void)disegnaGiornale;
-(void)nascondiBottoneMultimediale:(NSTimer*)timer;
-(IBAction)showCurrentOrder;
-(void)aggiungiArticolo:(id)sender;
-(bool)esistonoProdottiCorrelatiPagina:(int)x;
-(IBAction)disegnaProdottiCorrelati;
-(IBAction)disegnaProdottiAssociati;
-(void)ckButtonMarketCorrelati;
-(NSString *)realPageNumber:(NSString *)index;
-(NSString *)indexFromPageNumber:(NSString *)pageNumber;
-(void)vaiAlCorrelato:(id)sender;
-(IBAction)mostraPulsantiMultimediali;
-(IBAction)nascondiPulsantiMultimediali;
-(IBAction)nascondiVistaAcquista;


@property(nonatomic, strong)NSMutableArray *memoGost;
@property(nonatomic, strong)NSMutableDictionary *memoHL;
@property(nonatomic, strong)NSString *filePagine;
@property(nonatomic)int realhPag, realWPag, limitW, limitH;

@end
