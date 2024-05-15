

// リクエストボディを受け取って、型のチェックを行う
controller
type order {

}


Usecase
function RegisterOrder(order){
  transaction{
    Stock.remove;
    Orders.register;
  }
  return Result<Success(id), Error>
}



repository
interface{
  Stock{
    register
    remove
  }
  Orders{
    register
  }
}


infrastructure{
  
}
