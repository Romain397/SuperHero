#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "SuperHero.cpp"
#include "SpiderMan.cpp"
#include "IronMan.cpp"
#include "Hulk.cpp"
#include "DoctorStrange.cpp"
#include "Artifact.cpp"
#include "HealthPotion.cpp"
#include "PowerAmulet.cpp"
#include "CursedStone.cpp"

// Fonction qui gère le combat entre les super-héros
void fight(std::vector<SuperHero *> &heroes)
{
    // Boucle infinie qui continue jusqu'à ce qu'il ne reste qu'un seul héros en vie
    while (true)
    {
        // Boucle qui parcourt tous les héros dans le vecteur
        for (SuperHero *hero : heroes)
        {
            // Vérifie si le héros est en vie, sinon on passe au héros suivant
            if (!hero->isAlive())
                continue;

            // Affiche le tour du héros actuel
            std::cout << "\nTour de " << hero->getName() << "\n";
            // Affiche les points de vie du héros actuel
            std::cout << "PV: " << hero->getHealth() << "\n";

            // Affiche les cibles disponibles pour le héros actuel
            std::cout << "Cibles disponibles:\n";
            for (size_t i = 0; i < heroes.size(); ++i)
            {
                // Vérifie si la cible est en vie et différente du héros actuel
                if (heroes[i]->isAlive() && heroes[i] != hero)
                {
                    // Affiche le nom et les points de vie de la cible
                    std::cout << i + 1 << ". " << heroes[i]->getName() << " (PV: " << heroes[i]->getHealth() << ")\n";
                }
            }

            // Affiche les options disponibles pour le héros actuel
            std::cout << "1 - Attaque | 2 - Capacité spéciale | 3 - Artefact\n";

            // Récupère le choix de l'utilisateur
            int choice;
            std::cin >> choice;

            // Validation de l'entrée pour le choix d'action
            while (std::cin.fail() || choice < 1 || choice > 3)
            {
                std::cout << "Entrée invalide. Veuillez entrer un nombre valide: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n'); // Ignorer les caractères invalides
                std::cin >> choice;
            }

            // Pointeur pour stocker la cible de l'action
            SuperHero *target = nullptr;
            // Si l'utilisateur choisit d'attaquer ou d'utiliser une capacité spéciale
            if (choice == 1 || choice == 2)
            {
                // Récupère l'indice de la cible
                size_t targetIndex;
                std::cout << "Choisissez une cible: ";
                std::cin >> targetIndex;

                // Validation de l'entrée pour la cible
                while (std::cin.fail() || targetIndex < 1 || targetIndex > heroes.size() || !heroes[targetIndex - 1]->isAlive() || heroes[targetIndex - 1] == hero)
                {
                    std::cout << "Cible invalide. Veuillez choisir une cible valide: ";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cin >> targetIndex;
                }
                // Stocke la cible dans le pointeur target
                target = heroes[targetIndex - 1];
            }

            // Exécute l'action choisie par l'utilisateur
            switch (choice)
            {
            case 1:
                // Attaque la cible
                hero->attack(*target);
                break;
            case 2:
                // Utilise la capacité spéciale sur la cible
                hero->useSpecialAbility(*target);
                break;
            case 3:
            {
                // Affiche les options d'artefacts
                std::cout << "Choisissez un artefact: 1-Potion 2-Amulette 3-Pierre\n";
                // Récupère le choix de l'utilisateur pour l'artefact
                int artifactChoice;
                std::cin >> artifactChoice;

                // Validation de l'entrée pour l'artefact
                while (std::cin.fail() || artifactChoice < 1 || artifactChoice > 3)
                {
                    std::cout << "Entrée invalide. Veuillez entrer un nombre valide: ";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cin >> artifactChoice;
                }

                // Pointeur pour stocker l'artefact choisi
                Artifact *artifact = nullptr;
                // Crée l'objet artefact correspondant au choix de l'utilisateur
                if (artifactChoice == 1)
                    artifact = new HealthPotion();
                else if (artifactChoice == 2)
                    artifact = new PowerAmulet();
                else if (artifactChoice == 3)
                    artifact = new CursedStone();

                // Si un artefact a été créé
                if (artifact)
                {
                    // Applique l'effet de l'artefact au héros actuel
                    artifact->applyEffect(*hero);
                    // Libère la mémoire de l'artefact
                    delete artifact;
                }
                break;
            }
            default:
                // Affiche un message d'erreur si l'action choisie est invalide
                std::cout << "Action invalide !\n";
            }

            // Compte le nombre de héros encore en vie
            int aliveCount = 0;
            for (SuperHero *h : heroes)
                if (h->isAlive())
                    aliveCount++;

            // Si un seul héros est en vie, le combat est terminé
            if (aliveCount <= 1)
            {
                std::cout << "\nCombat terminé !\n";
                return;
            }
        }
    }
}

// Fonction principale du programme
int main()
{
    // Initialise le générateur de nombres aléatoires
    srand(time(0));

    // Crée un vecteur de pointeurs vers les super-héros
    std::vector<SuperHero *> heroes = {
        new SpiderMan("Spider-Man", 100, 15),
        new IronMan("Iron Man", 100, 20),
        new Hulk("Hulk", 100, 30),
        new DoctorStrange("Doctor Strange", 100, 18)};

    // Lance le combat
    fight(heroes);

    // Libère la mémoire des super-héros
    for (SuperHero *hero : heroes)
        delete hero;

    return 0;
}