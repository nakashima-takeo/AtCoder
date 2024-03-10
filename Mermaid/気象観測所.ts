export class WeatherData {
  public getTemperature(): number{
    return 0;
  }
  public getHumidity(): number{
    return 0;
  };
  public getPressure(): number{
    return 0;
  };

  public measurementsChanged(): void {
    const temp = this.getTemperature();
    const humidity = this.getHumidity();
    const pressure = this.getPressure();

    currentConditionsDisplay.update(temp, humidity, pressure);
    statisticsDisplay.update(temp, humidity, pressure);
    forcastDisplay.update(temp, humidity, pressure);
  }
}
