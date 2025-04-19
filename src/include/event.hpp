#ifndef EVENT_H
#define EVENT_H

class Event
{
    public:
        virtual void Start() {}
        virtual void Update() {}
        virtual void FixedUpdate() {}
        virtual ~Event() = default;  // Virtual destructor
};

#endif