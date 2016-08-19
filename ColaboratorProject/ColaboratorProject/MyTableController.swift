//
//  MyTableController.swift
//  ColaboratorProject
//
//  Created by Loc Nguyen on 8/19/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

import UIKit
import CSBMUI

class MyTableController: BEQueryTableViewController {
  
  override func viewWillAppear(animated: Bool) {
    loadObjects()
  }
  
  override func queryForTable() -> BEQuery! {
    let query = Model.query()
    
    return query
  }
  
    override func viewDidLoad() {
        super.viewDidLoad()

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
  
  override func tableView(tableView: UITableView!, cellForRowAtIndexPath indexPath: NSIndexPath!, object: BEObject?) -> BETableViewCell? {
    let cell = BETableViewCell()
    
    let database = object as! Model
    
    cell.textLabel?.text = object?.objectForKey(TodoColumn) as? String
    
    return cell
  }

}
