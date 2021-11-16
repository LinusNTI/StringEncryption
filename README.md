# StringEncryption
 
Quick example of a easy to use encryption class for both C# and C++

## Simple usage and assignments

C++
```cpp
EncryptedString secureString1 = string("Hello1");
EncryptedString secureString2("Hello2");
EncryptedString secureString3;

secureString3 = string("Hello3");

cout << (string)secureString1 << endl;
cout << (string)secureString2 << endl;
cout << (string)secureString3 << endl;
```

C#
```csharp
EncryptedString secureString1 = new EncryptedString("Hello1");
EncryptedString secureString2 = "Hello2";

Console.WriteLine(secureString1);
Console.WriteLine(secureString2);
```

<br><br>

## The classes can also be used like normal strings

C++
```cpp
void Test(string test) {
    cout << test << endl;
}

int main()
{
    EncryptedString test = string("Test");
    Test(test);
}
```

C#
```csharp
public void Test(string test) => Console.WriteLine(test);

public void Run() {
    EncryptedString secureString = "Test";
    Test(secureString);
}
```
