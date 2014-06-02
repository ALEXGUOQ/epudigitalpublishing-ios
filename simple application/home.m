//
//  home.m
//  EPUapi
//
//  Created by Simone Moreschi on 29/05/14.
//
//

#import "home.h"

@interface home ()

@end

@implementation home

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [self.navigationController setNavigationBarHidden:true animated:false];
    editions = [[NSMutableArray alloc] init];
    
    //  Init EPU
    //
    sharedSingleton = [EPUengine sharedInstance];
    sharedSingleton.apicode = @"test";
    sharedSingleton.book = @"73";

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(updateEditionsList) name:@"restart" object:nil];
}

-(void)updateEditionsList {
    [tbl setAlpha:0.0];
    [self performSelector:@selector(reloadData) withObject:nil afterDelay:0.1];
}

-(void)reloadData {
    EPUapiAppDelegate *mainDelegate = (EPUapiAppDelegate *)[[UIApplication sharedApplication]delegate];
    NSMutableDictionary *dict = [sharedSingleton getDataFromServer:mainDelegate.connettivita];
    editions = [dict objectForKey:@"editions"];
    [tbl reloadData];
    [tbl setAlpha:1.0];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [editions count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

    static NSString *MyIdentifier = @"cellEditionsList";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:MyIdentifier];
    if (cell == nil) {
        [[NSBundle mainBundle] loadNibNamed:@"cellEditionsList" owner:self options:nil];
        cell = cellEditionsList;
    }
    
    UILabel *label;
    label = (UILabel *)[cell viewWithTag:1];
    label.text = [[editions objectAtIndex:indexPath.row] objectForKey:@"titolo"];
    
    return cell;

}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 40;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    //  Set EPU edition number
    //
    sharedSingleton.edition = [[editions objectAtIndex:indexPath.row] objectForKey:@"code"];
    //  Open EPU view
    //
    [sharedSingleton openEPUView:self.navigationController animated:true];
}

@end