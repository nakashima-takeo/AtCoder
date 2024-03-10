export abstract class Beverage{
  private description = "不明な飲み物";

  constructor(description: string){
    this.description = description;
  }

  getDescription(): string{
    return this.description;
  }

  public abstract cost(): number;
}

export class Espresso extends Beverage{
  constructor(){
    super("エスプレッソ");
  }

  public cost(): number {
    return 2.02;
  }
}

export abstract class CondimentDecorator extends Beverage{
  protected beverage: Beverage;

  constructor(beverage: Beverage){
    super("");
    this.beverage = beverage;
  }
}  

export class Mocha extends CondimentDecorator{
  constructor(beverage: Beverage){
    super(beverage);
  }

  public getDescription(): string {
    return this.beverage.getDescription() + ", モカ";
  }

  public cost(): number {
    return this.beverage.cost() + 0.20;
  }
}

//　以下サンプルコード

let beverage = new Espresso();
console.log(beverage.getDescription() + " " + beverage.cost() + "ドル");

let beverage2 = new Espresso();
beverage2 = new Mocha(beverage2);
console.log(beverage2.getDescription() + " " + beverage2.cost() + "ドル");

let beverage3 = new Espresso();
beverage3 = new Mocha(beverage3);
beverage3 = new Mocha(beverage3);
console.log(beverage3.getDescription() + " " + beverage3.cost() + "ドル");

