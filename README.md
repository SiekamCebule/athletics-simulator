# athletics-simulator
Program do prostej symulacji wyników lekkoatletyki.<br><br>

# Folder resources
W tym folderze są pliki konieczne do poprawnego działania programu. Służą one do wczytywania zawodników danej dyscypliny i ustawień symulacji.

## Plik "simulationSettings.json"
Plik zawiera ustawienia symulacji dla każdej dycypliny.

# Dyscypliny 
*W nawiasie parametrów zawodnika podane są nazwy do wpisania w plikach zawodników .json
### Biegi
Parametry zawodnika: Tempo (paceSkill) i Kondycja (conditionSkill) <br>
### Skoki (w dal, trójskok)
Parametry zawodnika: Przyśpieszenie (accelarateSkill) i Skok (jumpSkill)


# Ustawienia symulacji:
```
"Running":[
{
"distance": 400,
"minResult": 27.80,
"randEffect": 0.65,
"paceSkillEffect": 0.54,
"conditionSkillEffect": 0.48
},
]
```

# -- Wersja robocza --
