//
//  Model.swift
//  ColaboratorProject
//
//  Created by Loc Nguyen on 8/19/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

import UIKit

class Model: BEObject, BESubclassing {
  @NSManaged var data: String?
  
  /**
   Define function to get class name - column table
   
   - returns: table name
   */
  class func parseClassName() -> String {
    return TableName
  }
  
  /**
   Constructor
   
   - returns: single object
   */
  override class func initialize() {
    var onceToken: dispatch_once_t = 0
    dispatch_once(&onceToken) {
      self.registerSubclass()
    }
  }
  
  override class func query() -> BEQuery? {
    let query = BEQuery(className: Model.parseClassName())
    
    return query
  }
  
  override init() {
    super.init()
  }
  
  init(data: String) {
    super.init()
    self.data = data
  }
}
