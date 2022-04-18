![image](https://github.com/parsecnode/parsec-icons/blob/main/PARSEC-zero_banner.png?raw=true)

This is the lite version of Parsec GUI. It works via remote daemon and doesn't store blockchain on your PC. The remote nodes are rewarded for their service. Parsec wallets, connected to masternode, are paying small additional fee (0.25% from the amount of transaction) to that node when are sending transactions through it. These fees are supposed to help to cover the costs of operating Parsec Nodes.

You can select remote node in Settings or add custom one. Go to menu Settings -> Preferences -> Connection tab to select Remote daemon.

Portable on Windows - stores wallet files, logs, config file in the same folder with executable, stores data in the default folder on Linux and Mac (`~/.parsec` and `~/Library/Application Support/parsec` respectively).

Comes with config containing the list of remote nodes.

It can import wallet files from [classic parsec wallet](https://github.com/parsecnode/parsecwallet) but it will take several minutes to refresh, and <b>new wallet file will be incompatible with classic wallet</b>.


**1. Clone wallet sources**

```
git clone https://github.com/parsecnode/Parsec-lite.git
```

**2. Set symbolic link to coin sources at the same level as `src`. For example:**

```
ln -s ~/parsec/cryptonote ~/Parsec-lite/
```

Alternative way is to create git submodule:

```
git submodule add https://github.com/parsecnode/parsec.git cryptonote
```

**3. Build**

```
mkdir build && cd build && cmake .. && make
```
BUILD FILES WILL BE LOCATED WITHIN THE FOLLOWING DIRECTORY: ~/Parsec-lite/build/
  
  *Run Parsec Wallet (linux) in command line: ./ParsecLite
