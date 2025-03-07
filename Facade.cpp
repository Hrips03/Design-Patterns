#include <iostream>

class FlightBookingSubsystem
{
public:
    void searchFlight() { std::cout << "Searching for a flight...\n"; }
    void bookFlight() { std::cout << "Flight is booked.\n"; }
    void cancelFlight() { std::cout << "Flight is canceled.\n"; }
    void selectSeats() { std::cout << "Seat is selected.\n"; }
};

class HotelReservationSubsystem
{
public:
    void checkHotelAvailability() { std::cout << "Checking hotel's availablility...\n"; }
    void roomSelection() { std::cout << "Room is selected.\n"; }
    void roomBooking() { std::cout << "Room is booked.\n"; }
};

class PaymentGatewaySubsystem
{
public:
    void proccesspayment() { std::cout << "payment is being proccessed...\n"; }
    void handleTransaction() { std::cout << "Transaction was successfull.\n"; }
};

class TravelFacade
{
    FlightBookingSubsystem *flights;
    HotelReservationSubsystem *hotels;
    PaymentGatewaySubsystem *payment;

public:
    TravelFacade()
    {
        flights = new FlightBookingSubsystem();
        hotels = new HotelReservationSubsystem();
        payment = new PaymentGatewaySubsystem();
    }

    void bookVacation()
    {
        flights->searchFlight();
        flights->selectSeats();
        flights->bookFlight();
        hotels->checkHotelAvailability();
        hotels->roomSelection();
        hotels->roomBooking();
        payment->proccesspayment();
        payment->handleTransaction();
    }
};

int main()
{
    TravelFacade *tourist = new TravelFacade();
    tourist->bookVacation();
}