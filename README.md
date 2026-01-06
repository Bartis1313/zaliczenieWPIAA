W projekcie jest 7 wzorców
- strategy
- state
- visitor
- observer
- template
- composite

## 1. Strategy
W grze dochodzi do wielu kolizji, i wielu ich typów, niektóre obiekty mog¹ zachowywaæ siê inaczej.
Dlatego ³atwo mo¿emy sprawdzaæ kolizje jakichkolwiek typów, w dodatku nie edytuj¹c ju¿ napisanego kodu wczeœniej

## 2. State
Obiekty mog¹ mieæ ro¿ne stany, w tym przypadku Idle b¹dŸ Destroyed.
Mo¿na stany utrzymywaæ w jednym enumie, ale wtedy w funckjach aktualizuj¹cych obiekty w czasie rzeczywistym musielibyœmy wprawadzaæ wiele if'ów typu:
```
if(state == STATE::DONE) ...
else if(state == STATE::POST_UPDATE) ...
```
co powoduje bardzo trudne w utrzymaniu

## 3. Visitor
Kiedy mamy wiele kolizji które pomóg³ nam strategy pattern, w momencie kiedy do niej dochodzi chcemy odseparowaæ niektóre obiekty.
W taki sposób, aby tylko jeden mia³ dodatkow¹ akcje, a reszta zostaje taka sama, albo ma inne edycje.
W tym przyk³¹dzie Gracz aktualizuje swój stan, gdzie Œciana nie, poniewa¿ jest to statyczny obiekt w grze.
Jedyny minus to ogromna iloœæ przeci¹¿eñ metod, co prawdopodobnie spowalnia œrodowisko IDE.

## 4. Factory
Tworzymy obiekt bez zagl¹dania w defnicje. Wszystko robi za nas factory, gdzie wiemy ¿e chcemy stworzyæ obiekt dziedzicz¹cy po GameObject.

## 5. Observer
Osobiœcie wole nazywaæ to EventHandler, poniewa¿ realnie tylko tu posiada dobre u¿ycie.
W przyk³adzie jest tylko logger który pomaga nam ziidentyfikowaæ nazwê zdarzenia. W realnym przypadku mo¿emy posiadaæ du¿o "subskrybentów", które robi¹ reaguj¹ na specjalne zdarzenia.

## 6. Template
Logger posiada bardzo prost¹ schematyke: flush i write. Lecz chcemy aby logger móg³ byæ w stanie pisaæ do konsoli, albo do pliku.
W obu przypadkach, implementacja write oraz flush zmienia siê.

## 7. Composite
Sam template w logerze powoduje jedno krytyczne zachowanie. Co jeœli u¿ytkownik chce aby logger pisa³ w konsoli i w pliku jednoczeœnie.
Przez to skorzysta³em z dodatkowego wzorca.

###### PS: nie pisa³em w œrodowisku .NET, ze wzglêdu na preferencje przyzwyczajenia.