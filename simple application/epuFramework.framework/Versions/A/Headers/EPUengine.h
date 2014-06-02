//
//  sharedInstance.h
//  epuapi
//
//  Created by Simone Moreschi on 14/05/14.
//  Copyright (c) 2014 moreschisimone. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "EpuViewController.h"

@interface EPUengine : NSObject <NSXMLParserDelegate> {
    
    NSString *tipo, *edition, *server, *utente, *localPath, *deviceDescription, *currentDevice, *book, *homeW, *homeH, *pathComprati, *hMode, *fbID, *fbcaller, *maxZoom, *gotoPageName, *pathMessaggioPreferito, *defHMODE, *apicode;
    NSMutableArray *arr, *arrDownload, *arrCercati, *arrPreferiti, *arrEditions, *arrSubscriptions;
    bool connettivita;
    int preventReload, i, doReload, mostraEdizione, H_windowW, H_windowH, V_windowW, V_windowH, progress, V_realW, V_realH, H_realW, H_realH, fillAbb, doAppearView, whiteLabel;
    
    //  Multimedia
    int curMultiPag, curMultiIdx, market, perc, gostPages, justSeePages, autoStartSingole, newsstand;
    NSString *curMultiTipo, *curMultiData, *curMultiFoto, *imgTopLeft, *agent;
    
    int isPreviewing, indiceGallery, epuLog;
    
    // parser XML
	NSXMLParser *rssParser;
	// elenco degli elementi letti dal feed
	NSMutableArray *elencoFeed, *elencoLingue, *elencoOrdine, *currentEdizione, *icarouselPhoto;
	//v®ariabile temporanea per ogni elemento
	NSMutableDictionary *item;
	// valori dei campi letti dal feed
	NSString *currentElement, *modo, *curAcquisto, *currentConsumabile;
    NSString *curCkPerc, *systemLanguage, *fatherRivista, *curCliente, *curNote, *gotoPage, *versione, *pkOrdine, *pkOrdineModifica, *strAbb, *strInfo;
    
    float ckConnection;
    
    int justDownloadRemote, isShowingMultimedia;
    NSMutableArray *memoCopertine;
    
    NSString *searchForText, *subscriptionTransactionId;
    NSString *titoloEdizione, *prezzoEdizione, *idEdizione;
    NSString *pathPreferiti, *localDoc;
    
    NSMutableString *strhmode, *strNome, *strCode, *strDescrizione, *strPrezzo, *strIdPrezzo, *strTipo, *strConsumabile, *prevnumpage, *isfolder, *strgoToPage, *strgoToPageImage;
}

+ (id)sharedInstance;


-(void)sendSignalToApp:(NSMutableDictionary *)dict;
-(void)openEPUView:(UINavigationController *)nc animated:(bool)animated;
-(void)salvaPercentuale:(int)ind diTot:(int)tot ediz:(NSString *)ediz;
-(void)scaricaUscita:(NSString *)pagine uscita:(NSString *)ediz preview:(int)preview;
-(void)annullaScarica:(NSString *)ediz;
-(int)getIndexOfDownload:(NSString *)thisEdizione;
- (void)parseXMLFile:(NSString *)path;
-(NSMutableDictionary *)getDataFromServer:(bool)online;


//  Proprietà
@property (nonatomic, strong) NSString *systemLanguage, *tipo, *edition, *server, *utente, *localPath, *usrAnalytics, *deviceDescription, *currentDevice, *book, *homeW, *homeH, *pathComprati, *curAcquisto,*curMultiTipo, *curMultiData, *curMultiFoto, *hMode, *curCliente, *curNote, *gotoPage, *versione, *pkOrdine, *pkOrdineModifica, *maxZoom, *strAbb, *currentConsumabile, *strInfo, *fbCaller, *fatherRivista, *fbID, *searchForText, *titoloEdizione, *prezzoEdizione, *idEdizione, *pathPreferiti, *localDoc, *gotoPageName, *pathMessaggioPreferito, *imgTopLeft, *defHMODE, *agent, *subscriptionTransactionId, *apicode;
@property (nonatomic, strong) NSMutableArray *arr, *arrDownload, *abb, *elencoLingue, *elencoOrdine, *currentEdizione, *memoCopertine, *arrCercati, *arrPreferiti, *icarouselPhoto;
@property(nonatomic)bool connettivita;
@property(nonatomic)int epuLog, indiceGallery, whiteLabel, gostPages, iad, market, preventReload, i, doReload, mostraEdizione, H_windowW, H_windowH, V_windowW, V_windowH, progress, V_realW, V_realH, H_realW, H_realH, curMultiPag, curMultiIdx, fillAbb, perc, justSeePages, autoStartSingole, doAppearView, newsstand, justDownloadRemote, isShowingMultimedia, isPreviewing;

@end