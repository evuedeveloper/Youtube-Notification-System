#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Interface to create multiple subscribers as our users
class Subscriber
{
public:
    std::string emailId;
    Subscriber(std::string mailId) : emailId(mailId) {};
    virtual void OnUpdate(const std::string videoLink)=0;
};

//Interface to create different concrete notification manager
class NotificationManager
{
public:
    virtual void Subscribe(Subscriber* subscriber) = 0;
    virtual void UnSubscribe(Subscriber* subscriber) = 0;
    virtual void NotifyAllSubscribers() = 0;
};

//concrete notification manager, from our NotificationManager Interface
class SubscriberNotificationManager : public NotificationManager
{
    std::string videoLink;
    std::vector<Subscriber*> listOfSubscribers;
public:
    //add subscriber to the list
    void Subscribe(Subscriber* subscriber)
    {
        listOfSubscribers.push_back(subscriber);
    }

    //remove subscriber from the list
    void UnSubscribe(Subscriber* subscriber)
    {
        listOfSubscribers.erase(std::remove(listOfSubscribers.begin(), listOfSubscribers.end(), subscriber), listOfSubscribers.end());
    }

    //notify all the subscribers present in the list
    void NotifyAllSubscribers()
    {
        for(const auto& subscriber : listOfSubscribers)
        {
            subscriber->OnUpdate(videoLink);
            cout << "Subscriber:\t" << subscriber->emailId << " has been notified"<< std::endl;
            std::cout << "*******************************************************************************"<< std::endl;
        }
    }

    void VideoUploaded(std::string videoLink)
    {
        this->videoLink = videoLink;
        NotifyAllSubscribers();
    }
};

class ChannelSubscriber : public Subscriber
{
public:
    ChannelSubscriber(std::string mailId) : Subscriber(mailId){};

    //this function will be called by the notification manager
    //to inform the subscriber about content update
    void OnUpdate(const std::string videoLink)
    {
        cout << "There is a new video on the channel. Video Link: " << videoLink << std::endl;
    }
};

int main()
{
    SubscriberNotificationManager* nm = new SubscriberNotificationManager();

    Subscriber* sb = new ChannelSubscriber("ankandas194@gmail.com");
    nm->Subscribe(sb);

    Subscriber* sb1 = new ChannelSubscriber("xyz@gmail.com");
    nm->Subscribe(sb1);

    nm->VideoUploaded("Youtube/VideoUploadedByChannel");

    cout<<"removing Mr. sb2's subscription from our notification"<<std::endl;
    nm->UnSubscribe(sb1);

    nm->VideoUploaded("Youtube/newVideoUploadByChannel");
    return 0;
}

/*
Implementation Output:
There is a new video on the channel. Video Link: Youtube/VideoUploadedByChannel
Subscriber:     ankandas194@gmail.com has been notified
*******************************************************************************
There is a new video on the channel. Video Link: Youtube/VideoUploadedByChannel
Subscriber:     xyz@gmail.com has been notified
*******************************************************************************
removing Mr. sb2's subscription from our notification
There is a new video on the channel. Video Link: Youtube/newVideoUploadByChannel
Subscriber:     ankandas194@gmail.com has been notified
*******************************************************************************
*/
