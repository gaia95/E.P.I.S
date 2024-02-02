# E.P.I.S
Projekt Presentation: 

Välkommen till mitt projekt!
I detta arbetet har jag jobbat med att desgina en sensorbaserad varningssystem för riskhantering av vatten. 

Bakgrund och Motivation:

Utgångspunkten för detta projekt var en nyhetsartikel på Aftonbladet som rapporterade om översvämningar. Detta väckte min uppmärksamhet och fick mig att fundera över hur vi kan förebygga skador och rädda liv i händelse klimatförändringar samt dess konsekvenser.

Målet var att skapa en lösning med hjälp av en vattensensor, som skulle kunna upptäcka vatten och vidarebefordra relevanta data till en LCD-skärm. Genom detta skulle vi kunna ge tydliga varningar beroende på vattennivåerna och därigenom minimera risken för skador och förlust av liv.

Ursprunglig Fokus och Utvidgning:

I början var tanken att skapa en lösning endast för övervakning av vattennivåer. Men under arbetets gång övervägde jag även andra naturkatastrofer, såsom tsunamis. Jag funderade på möjligheten att utveckla en enhet som kunde ge varningar för olika scenarier. Ett exempel är att detektera ovanligt havsbeteende och avvikelse från kusten som indikationer på en möjlig tsunami.

Arbetsprocess: 

För att förstå och implementera projektet började jag med att fördjupa mig i Arduino genom att studera Tutorials Point och titta på Youtube-videor. Det var viktigt att förstå grundläggande funktioner och hur man kopplar samman olika komponenter på en Arduino-bräda.

Komponentlista och motivering
- LCD skärm: För display av varningsmeddelande och distans.
- Krets Bord: För att koppla samman alla komponenter till varandra.
- Arduino Bräda: För att kunna läsa av värden från sensorerna och
sammankoppla dem med samtliga sensorer.
- LED Lamp: Ska fungera som en varningslampa
- Resistor: För att ge resistans och gränslägga strömkret. Förhindrar att
glödlampan och LCD går sönder på grund av för hög volt.
- Potentiometer: reglerbar resistor då det kan vara bra att kunna kontrollera
strömmen.
- Distans sensor: Ska mäta avståndet genom att skicka ut pulserande
ljudvågor (Trigger) och se hur lång tid det tar för ljudvågorna att komma tillbaka som ett eko (Echo) efter att ha nått mottagaren/objektet.

GOOD LEVELS:

![](GL.png)

ISSUING WARNING:

![](Warning%20.png)


KOD REDOVISNING:

Jag började med #include för att inkludera de nödvändiga bibliotek för detta projekt. 

void setup():

Startade kommunikationen mellan arduinon och enheterna som den sänder och mottar information från (LCD, LED, Sensor). 
Eftersom arduino har en pin med inbygg lampa (pin 13) är den kopplade till glödlampan.
TP står för Trigger Pin och representerar den del av distans sensorn som sänder ut ljudvågor/pulsvågor. Den är satt till OUTPUT då den ska sända ut signaler. 
EP Står för Echo Pin och representerar den del som ska lyssna efter ljudvågorna som TP sänder ut. EP är satt till INPUT då den inväntar vågorna.

void loop():

I denna fas implementerade jag koden för avståndsmätaren för att säkerställa kontinuerlig mätning av distansen 
och konstant övervakning av vattennivåerna.

Då denna mätaren ska skicka ut varningar endast om det förekommer en fara, så har jag tillagt If-satser. 
Dessa satser utgår ifrån hur värdena, som sensorn hämtar in, ser ut. Om ett villkor är sant, (antingen att distansen är för stor eller för liten) går varningen igång. Tillade även en liten fördröjning så att det ska bli en blinkande effekt så att man faktiskt ska bli uppmärksammad.

-----

Problem och motgångar:

- Tanken var att använda en vattensensor för detektion av vatten, dock fanns det inte med på simulator hemsidan.
  För att försöka lösa problemet på ett annat sätt valde jag istället en distansmätare som ska mäta avståndet till vattnet både horisontellt och vertikalt.

- Fick inte igång LCD skärmen. Misstankarna låg kring huruvida sladdarna var felkopplade. Det visade sig att det var en fråga om själva simulatorn som verkade känslig   för siffror. Problemet löstes genom att skriva dem i en annan ordning.
  
- Hade problem med att få mina "Good levels" kontra varningar att dyka upp på LCD - skärmen beroende på värdena. Löste det med en enkel if-sats.

-----
  
Detta projekt var roligt att utföra men i min åsikt, långt ifrån färdig då jag tycker att varje projektide alltid kan förbättras.
Det finns självklart fler faktorer att ha i åtanke, men detta är iallafall en början. 

