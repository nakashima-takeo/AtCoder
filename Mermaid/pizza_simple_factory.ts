export class PizzaStore{
  constructor(){}

  orderPizza(type: string){
    const pizza = SimplePizzaFactory.createPizza(type);
  
    pizza.prepare();
    pizza.bake();
    pizza.cut();
    pizza.box();
    return pizza;
  }
}

export class SimplePizzaFactory{
  static createPizza(type: string): Pizza{
    let pizza: Pizza;
    if (type === "チーズ"){
      pizza = new CheesePizza();
    } else if(type === "ギリシャ"){
      pizza = new GreekPizza();
    } else if(type === "ペパロニ"){
      pizza = new PepperoniPizza();
    } else {
      throw new Error("指定されたピザはありません。");
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

export class CheesePizza extends Pizza{
  constructor(){
    super();
    this.name = "チーズピザ";
    this.dough = "薄いクラスト生地";
    this.sauce = "マリナラソース";
    this.toppings.push("レッジャーノチーズ");
  }
}

export class GreekPizza extends Pizza{
  constructor(){
    super();
    this.name = "ギリシャピザ";
    this.dough = "薄いクラスト生地";
    this.sauce = "マリナラソース";
    this.toppings.push("フェタチーズ");
  }
}

export class PepperoniPizza extends Pizza{
  constructor(){
    super();
    this.name = "ペパロニピザ";
    this.dough = "薄いクラスト生地";
    this.sauce = "マリナラソース";
    this.toppings.push("ペパロニ");
  }
}
