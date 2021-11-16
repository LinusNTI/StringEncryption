using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows;
using System.Threading.Tasks;

namespace StringEncryptionCSharp
{
    class MyProgram
    {
        public void Run()
        {
            bool isRunning = true;
            while (isRunning)
            {
                Console.Clear();
                Console.WriteLine("[1] Encrypt strings\n[2] Decrypt strings");
                var key = Console.ReadKey(true).Key;
                switch (key)
                {
                    case ConsoleKey.D1: //Encrypt
                        Console.Clear();
                        Console.WriteLine("Please enter a string to encrypt:");

                        var userString = Console.ReadLine();
                        EncryptedString encrypted = new EncryptedString(userString);

                        Console.Clear();
                        Console.WriteLine("Encrypted (Copied to your clipboard): " + encrypted.GetEncrypted());
						
                        // Credits to equiman on StackOverflow for this class
                        // Source: https://stackoverflow.com/a/51912933/12524368
                        WindowsClipboard.SetText(encrypted.GetEncrypted());
						
                        Console.ReadKey(true);
                        break;
                    case ConsoleKey.D2:
                        Console.Clear();
                        Console.WriteLine("Please enter a string to decrypt:");

                        var userCryptString = Console.ReadLine();
                        EncryptedString encrypted2 = EncryptedString.FromEncrypted(userCryptString);

                        Console.WriteLine("Decrypted: " + encrypted2);
                        Console.ReadKey(true);
                        break;
                }
            }

            Thread.Sleep(-1);
        }
    }
}
