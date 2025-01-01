#include <iostream>
#include <memory>

#include "AdapterPattern.h"
#include "Cloud-Storage.h"
#include "BridgeRefactor.h"
#include "CompositePattern.h"

using namespace std;

int main()
{
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


    //++++ BRIDGE DESIGN PATTERN +++
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

    // ++++ COMPOSITE PATTERN ++++
    Book book1{ "Book", 4.99 };
    Toy toy1{ "Toy 1", 5.99 };
    Toy toy2{ "Toy 2", 10.99 };

    // Create box and add products and other boxes to them
    Box smallBox{ "Small Box" };
    
    smallBox.addProduct(book1);
    smallBox.addProduct(toy1);
    
    Box bigBox("Big Box");
    bigBox.addProduct(toy2);
    bigBox.addProduct(smallBox);

    // Calculate price
    cout << "Calculating total price...\n" << bigBox.price() << endl;

    // COMPOSITE CHALLENGE
    Circle c(5);
    Rectangle r(10, 20);
    Triangle t(3, 4, 5);

    //Create composite shape
    CompositeShape cs;

    cs.addShape(c);
    cs.addShape(t);
    cs.addShape(r);

    // Draw the composite shape
    cs.draw();

    //Remove Shape
    cs.removeShape(t);

    cs.draw();

    return 0;
}

