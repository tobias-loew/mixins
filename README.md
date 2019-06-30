# mixins
Mixin support for MFC-classes

Mixin is a well-known concept in software development (cf. https://en.wikipedia.org/wiki/Mixin). 
In C++ a mixin is usually a template class of the following form:
```
template<typename Base>
class Mixin : public Base {
...
};
```
So, a mixin doesn't have a fixed base-class but may impose requirements on the injected base-class
such as the existence of certain methods used in the implementation of the mixin.
Furthermore if there a to mixins, `MixinA` and `MixinB` that implement orthogonal features for the same base class `Base`, 
then those mixin can be combined easily by "inheriting" from both mixins with `MixinA<MixinB<Base>>`.
The latter feature is what makes mixin a very interesting concept when extending class-libraries.    

One of those class-libraries are the Microsoft-Foundation-Classes (MFC). Its initial release dates back to 1992 and 
it was originally designed as a wrapper for the Win32-API but also contains additional features like support for serialization, an application
framework or containers based on template.
One of the core features of the MFC is a class called `CWnd` which wraps an HWND window-handle. Even the MFC derives many classes from `CWnd`, e.g.
classes for dialogs, dialog-controls or other specialized windows-classes used in the application-framework.
When you search the net (e.g. codeproject.com) there are plenty more specializations of MFC-classes.

But among all these cool classes there is usually one caveat: the don't mix which each other. 
Almost all of the code uses fixed base classes and MFC's message-dispatching mechanism only work for the first base-class. 
(Multiple inheritance is supported, but may be at most one CWnd-derived base, which has to come first.)

Here mixin can come to the rescue. The only problem is that the MFC uses macros to register the message-handler methods (so-called message-maps). 
Unfortunately, those macros are incompatible with template classes and header-only libraries.
This project provides a new set of message-map macros which allow their definition inside in the class definition. 
(In both, classes and template-classes.)

So, take a look at the example and write your next control, dialog or other window-extension as a mixin!

Two things to mention at the end:
* a class-extension can be turned quite easily into a template-class using refactoring (e.g. with Visual Studio)
* there is an article about mixins on Jonathan Boccara's Fluent C++ blog (https://www.fluentcpp.com/2017/12/12/mixin-classes-yang-crtp)
