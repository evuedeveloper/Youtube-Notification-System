# Youtube-Notification-System

<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Project README</title>
</head>
<body>

<h1>Subscriber Interface:</h1>

<ol>
    <li><strong>Purpose:</strong> Defines the contract for subscribers. Any class inheriting from this interface must implement the OnUpdate() method.</li>
    <li><strong>Details:</strong>
        <ul>
            <li>Subscriber is an abstract base class/interface.</li>
            <li>It has a pure virtual method OnUpdate() to be implemented by concrete subscriber classes.</li>
        </ul>
    </li>
    <li><strong>Implementation:</strong>
        <ul>
            <li>Contains a constructor to initialize the email ID of the subscriber.</li>
            <li>Provides a pure virtual function OnUpdate() that takes a videoLink parameter.</li>
        </ul>
    </li>
</ol>

<h1>NotificationManager Interface:</h1>

<ol>
    <li><strong>Purpose:</strong> Defines the contract for concrete notification managers.</li>
    <li><strong>Details:</strong>
        <ul>
            <li>NotificationManager is an abstract base class/interface.</li>
            <li>It declares methods for subscribing, unsubscribing, and notifying subscribers.</li>
        </ul>
    </li>
    <li><strong>Implementation:</strong>
        <ul>
            <li>Contains pure virtual methods Subscribe(), UnSubscribe(), and NotifyAllSubscribers().</li>
        </ul>
    </li>
</ol>

<h1>SubscriberNotificationManager Class:</h1>

<ol>
    <li><strong>Purpose:</strong> Concrete implementation of the NotificationManager interface.</li>
    <li><strong>Details:</strong>
        <ul>
            <li>SubscriberNotificationManager manages subscribers and notifies them about updates.</li>
            <li>It maintains a list of subscribers and a video link to be notified about.</li>
        </ul>
    </li>
    <li><strong>Implementation:</strong>
        <ul>
            <li>Implements methods to subscribe, unsubscribe, and notify subscribers.</li>
            <li>Provides a method VideoUploaded() to trigger notifications when a new video is uploaded.</li>
        </ul>
    </li>
</ol>

<h1>ChannelSubscriber Class:</h1>

<ol>
    <li><strong>Purpose:</strong> Concrete subscriber class.</li>
    <li><strong>Details:</strong>
        <ul>
            <li>ChannelSubscriber represents a subscriber who receives notifications about new video uploads.</li>
        </ul>
    </li>
    <li><strong>Implementation:</strong>
        <ul>
            <li>Inherits from Subscriber interface.</li>
            <li>Implements the OnUpdate() method to handle video update notifications.</li>
        </ul>
    </li>
    <li><strong>Usage:</strong>
        <ul>
            <li>In the main() function:
                <ol>
                    <li>Create an instance of SubscriberNotificationManager.</li>
                    <li>Create instances of ChannelSubscriber and subscribe them to the manager.</li>
                    <li>Trigger a video upload event using VideoUploaded() method of the manager.</li>
                    <li>Optionally, unsubscribe a subscriber using UnSubscribe().</li>
                    <li>Trigger another video upload event to observe the notification behavior.</li>
                </ol>
            </li>
        </ul>
    </li>
</ol>

<h1>Object-Oriented Concepts:</h1>

<ul>
    <li><strong>Abstraction:</strong> Interfaces Subscriber and NotificationManager provide an abstraction for subscribers and notification managers, respectively.</li>
    <li><strong>Encapsulation:</strong> Member functions and data are encapsulated within classes, promoting data hiding and encapsulation.</li>
    <li><strong>Inheritance:</strong> ChannelSubscriber inherits from Subscriber, implementing its interface.</li>
    <li><strong>Polymorphism:</strong> Polymorphic behavior is achieved through virtual functions (OnUpdate()), allowing different subscriber types to react differently to updates.</li>
</ul>

<h1>Observer Design Pattern:</h1>

<ul>
    <li><strong>Subject (Observable):</strong> SubscriberNotificationManager acts as the subject. It maintains a list of subscribers and notifies them about updates.</li>
    <li><strong>Observer:</strong> ChannelSubscriber represents the observer. It receives notifications about new video uploads.</li>
    <li><strong>Loose Coupling:</strong> Subscribers (ChannelSubscriber) are loosely coupled with the subject (SubscriberNotificationManager). They don't need to know the internal details of the manager.</li>
    <li><strong>Notification:</strong> When a new video is uploaded, the manager notifies all subscribers by calling their OnUpdate() method.</li>
</ul>

</body>
</html>
