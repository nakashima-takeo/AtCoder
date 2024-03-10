export abstract class PizzaStore{
  constructor(){}

  orderPizza(type: string){
    const pizza = this.createPizza(type);
  
    pizza.prepare();
    pizza.bake();
    pizza.cut();
    pizza.box();

    return pizza;
  }

  abstract createPizza(type: string): Pizza;
}

export class NYPizzaStore extends PizzaStore{
  createPizza(type: string): Pizza{
    let pizza: Pizza;
    if(type === "チーズ"){
      pizza = new NYCheesePizza();
    }else if(type === "ギリシャ"){
      pizza = new NYGreekPizza();
    }else if(type === "ペパロニ"){
      pizza = new NYPepperoniPizza();
    } else {
      throw new Error("そのピザはありません。");
    }
    return pizza;
  }
}

export class ChicagoPizzaStore extends PizzaStore{
  createPizza(type: string): Pizza{
    let pizza: Pizza;
    if(type === "チーズ"){
      pizza = new ChicagoCheesePizza();
    }else if(type === "ギリシャ"){
      pizza = new ChicagoGreekPizza();
    }else if(type === "ペパロニ"){
      pizza = new ChicagoOriginalPizza();
    } else {
      throw new Error("そのピザはありません。");
    }
    return pizza;
  }
}

export abstract class Pizza{
  name: string;
  dough: string;
  sauce: string;
  toppings: string[] = [];

  prepare(): void{
    console.log(this.name + "を準備します。");
  }

  bake(): void{
    console.log(this.name + "を焼きます。");
  }

  cut(): void{
    console.log(this.name + "をカットします。");
  }

  box(): void{
    console.log(this.name + "を箱詰めします。");
  }

  getName(): string{
    return this.name;
  }
}

export class NYCheesePizza extends Pizza{
  constructor(){
    super();
    this.name = "チーズピザ";
    this.dough = "薄いクラスト生地";
    this.sauce = "マリナラソース";
    this.toppings.push("レッジャーノチーズ");
  }
}

export class NYGreekPizza extends Pizza{
  constructor(){
    super();
    this.name = "ギリシャピザ";
    this.dough = "薄いクラスト生地";
    this.sauce = "マリナラソース";
    this.toppings.push("フェタチーズ");
  }
}

export class NYPepperoniPizza extends Pizza{
  constructor(){
    super();
    this.name = "ペパロニピザ";
    this.dough = "薄いクラスト生地";
    this.sauce = "マリナラソース";
    this.toppings.push("ペパロニ");
  }
}

export class ChicagoCheesePizza extends Pizza{
  constructor(){
    super();
    this.name = "チーズピザ";
    this.dough = "厚いクラスト生地";
    this.sauce = "プラムトマトソース";
    this.toppings.push("モッツァレラチーズ");
  }
}

export class ChicagoGreekPizza extends Pizza{
  constructor(){
    super();
    this.name = "ギリシャピザ";
    this.dough = "厚いクラスト生地";
    this.sauce = "プラムトマトソース";
    this.toppings.push("フェタチーズ");
  }
}

export class ChicagoOriginalPizza extends Pizza{
  constructor(){
    super();
    this.name = "オリジナルピザ";
    this.dough = "厚いクラスト生地";
    this.sauce = "プラムトマトソース";
    this.toppings.push("モッツァレラチーズ");
  }
}
