//
//  preferiti.h
//  last
//
//  Created by Simone Moreschi on 26/07/13.
//
//

#import <Foundation/Foundation.h>
#import "EPUengine.h"

@interface preferiti : NSObject <NSXMLParserDelegate> {
    
    // parser XML
	NSXMLParser *rssParser;
    
	// elenco degli elementi letti dal feed
	NSMutableArray *elencoFeed;
    NSMutableArray *elenco_multi;
    NSMutableDictionary *item;
    NSMutableDictionary *item_multi;
    
    NSString *currentElement;
    
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
    NSMutableString *strEdizione;
    
    NSString *formatoPagina;
    NSString *formatoMiniatura;
    
}

-(bool)verificaPresenzaPreferito:(NSString *)nomePagina;

-(void)aggiungiPreferito:(NSMutableDictionary *)pagina edizione:(NSString *)edizione;

-(void)rimuoviPreferito:(NSMutableDictionary *)pagina;

@property(nonatomic, strong)NSMutableArray *elencoFeed;
@property(nonatomic, strong)NSString *formatoPagina, *formatoMiniatura;

@end