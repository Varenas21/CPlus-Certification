#include <iostream>
#include <memory>
#include <tuple>

#include "AdapterPattern.h"
#include "Cloud-Storage.h"
#include "BridgeRefactor.h"
#include "CompositePattern.h"
#include "DecoratorPattern.h"
#include "FacadePattern.h"
#include "FlyweightPattern.h"
#include "ProxyPattern.h"

using namespace std;

int main()
{
#pragma region Adapter Pattern
    //// ++++ ADAPTER PATTERN ++++
    ////=== COMPONENT ===
    //const unique_ptr<Component> components[] //Creates an array of components
    //{
    //    make_unique<ConcreteComponentA>(),
    //    make_unique<ConcreteComponentB>(),
    //    make_unique<LegacyAdapter>(),
    //    make_unique<LegacyClassAdapter>()
    //   //make_unique<LegacyComponent>() //Triggers compiler error, no viable conversion
    //};

    //for (const auto& component : components) // Iterates through each and executes the run() function
    //{
    //    component->run(); // Polymorphism
    //}
 

    //// Create an array of pointers to CloudStorage objects.
    //const unique_ptr<CloudStorage> cloudServices[]
    //{
    //    make_unique<CloudDrive>(),
    //    make_unique<FastShare>(),
    //    make_unique<LegacyAdapterCloud>()
    //};

    //// Iterate through an array and invoke the uploadContents and getFreeSpace
    //// Methods on each object
    //const string content = "Beam up";
    //for (const auto& service : cloudServices)
    //{
    //    service->uploadContents(content);
    //    service->getFreeSpace();
    //    cout << endl;
    //}
#pragma endregion
#pragma region Bridge Pattern
    // Solves the inheritance explosion problem by switching from inheritance to object composition

    //PlainTextHandler handler = PlainTextHandler();
    //EncryptedTextHandler encryptHandler = EncryptedTextHandler();

    //// Create an array of pointers to CloudStorage objects
    //const std::unique_ptr<ITextSharer> sharingServices[]
    //{
    //    make_unique<EmailShare>(handler),
    //    make_unique<EmailShareEncrypted>(encryptHandler)
    //};

    // Iterate through the array and invoke the uploadContents and getFreeSpace methods on each object
    //const string content = "Beam me up";
    //for (const auto& service : sharingServices)
    //{
    //    service->shareText(content);
    //    cout << endl;
    //}

    //// CHALLENGE
    //auto gasEngine = GasEngine();
    //auto electricEngine = ElectringEngine();
    //auto hybridEngine = HybridEngine();

    //const unique_ptr<IVehicle> vehicles[]
    //{
    //    make_unique<Car>(gasEngine),
    //    make_unique<Truck>(electricEngine)
    //};

    //for (const auto& vehicle : vehicles)
    //{
    //    vehicle->drive();
    //    cout << endl;
    //}
#pragma endregion
#pragma region Composite Pattern
    //Book book1{ "Book", 4.99 };
    //Toy toy1{ "Toy 1", 5.99 };
    //Toy toy2{ "Toy 2", 10.99 };

    //// Create box and add products and other boxes to them
    //Box smallBox{ "Small Box" };
    //
    //smallBox.addProduct(book1);
    //smallBox.addProduct(toy1);
    //
    //Box bigBox("Big Box");
    //bigBox.addProduct(toy2);
    //bigBox.addProduct(smallBox);

    //// Calculate price
    //cout << "Calculating total price...\n" << bigBox.price() << endl;

    //// COMPOSITE CHALLENGE
    //Circle c(5);
    //Rectangle r(10, 20);
    //Triangle t(3, 4, 5);

    ////Create composite shape
    //CompositeShape cs;

    //cs.addShape(c);
    //cs.addShape(t);
    //cs.addShape(r);

    //// Draw the composite shape
    //cs.draw();

    ////Remove Shape
    //cs.removeShape(t);

    //cs.draw();
#pragma endregion
#pragma region Decorator Pattern
    //auto desktop = new Desktop();
    //cout << desktop->description() << " costs $" << desktop->price() << endl;

    //auto laptop = new Laptop();
    //cout << laptop->description() << " costs $" << laptop->price() << endl;

    //auto desktopMemoryUpgrade = new MemoryUpgradeDecorator(desktop);
    //cout << desktopMemoryUpgrade->description() << " costs $" << desktopMemoryUpgrade->price() << endl;

    //auto laptopMemoryUpgrade = new MemoryUpgradeDecorator(laptop);
    //cout << laptopMemoryUpgrade->description() << " costs $" << laptopMemoryUpgrade->price() << endl;

    //delete desktop;
    //delete laptop;
    //delete desktopMemoryUpgrade;
    //delete laptopMemoryUpgrade;

    //Pizza* hawaiianPizza = new HawaiianPizza();
    //Pizza* pepperoniPizza = new PepperoniPizza();
    //Pizza* margheritaPizza = new MargheritaPizza();

    //// Decorate pizzas with toppings
    //Pizza* hawaiianWithCheese = new ToppingCheese(hawaiianPizza);
    //Pizza* pepperoniWithMushrooms = new ToppingMushroom(pepperoniPizza);

    //// Output descriptions and prices
    //cout << hawaiianWithCheese->description() << " - $" << hawaiianWithCheese->price() << endl;
    //cout << pepperoniWithMushrooms->description() << " - $" << pepperoniWithMushrooms->price() << endl;

    //// Cleanup
    //delete hawaiianWithCheese;
    //delete pepperoniWithMushrooms;
    //delete hawaiianPizza;
    //delete pepperoniPizza;

#pragma endregion
#pragma region FacadePattern
//ReservationSystemFacade reservationSystem;
//const string reservation = "Room rsvp info";
//const string paymentInfo = "Payment info";
//
//reservationSystem.makeReservation(reservation, paymentInfo);
//
//WeatherFacade weatherFacade;
//auto const location = "Location";
//
//auto weather = weatherFacade.currentWeather(location);
//
//float temperature = get<0>(weather);
//float humidity = get<1>(weather);
//string description = get<2>(weather);
//
//// Output the values
//cout << "Temperature: " << temperature << "�F" << endl;
//cout << "Humidity: " << humidity << "%" << endl;
//cout << "Description: " << description << endl;
//
#pragma endregion
#pragma region FlyWeightPattern
vector<Sprite*> sprites;
const int numSprites = 10;
const string textureFile = "Spaceship.png";

SpriteFactory factory;

for (int i = 0; i < numSprites; ++i)
{
    auto sprite = factory.makeSprite(textureFile);
    sprite->setPositionSize(10, 10, 10 * i, 10 * i);
    sprites.push_back(sprite);
}

// Draw all sprites
for (auto& sprite : sprites) sprite->render();



#pragma endregion
#pragma region ProxyPattern
//RealConfigFile configFile("config.txt");

ConfigFileProxy configFile("config.txt");
bool useSettings = false;
if (useSettings)
{
    vector<string> settings = configFile.getSettings();
    for (const auto& setting : settings) cout << setting << endl;
}
else cout << "Configuration not used \n";

// Challenge
string userInput;
cout << "Access Code Required: \n";
cin >> userInput;

SecureStorageProxy UserAccessCode("INFORMATION !!! ", userInput);

cout << "Inforamtion: " << UserAccessCode.getContents() << endl;
#pragma endregion


    return 0;
}

