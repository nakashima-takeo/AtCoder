export class Singleton {
  private static instance: Singleton;

  private constructor() {}

  public static getInstance(): Singleton {
    if (!Singleton.instance) {
      Singleton.instance = new Singleton();
    }
    return Singleton.instance;
  }

  // 他の便利なメソッド
}


export class Singleton_apriori{
  private static uniqueInstance = new Singleton_apriori();

  private constructor(){}

  public static getInstance(): Singleton_apriori{
    return this.uniqueInstance;
  }

  // 他の便利なメソッド
}
