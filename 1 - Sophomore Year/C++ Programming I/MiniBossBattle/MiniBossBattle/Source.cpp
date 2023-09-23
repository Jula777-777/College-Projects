#include <iostream>
#include <vector>
#include <string>
using namespace std;
enum class MolecularBond { covalent, ionic, metallic, hydrogenBonding, vanDerWaals };
struct Atom
{
	float weight;
	string name;
	string abbreviation;
	int atomicNumber;
};
struct Molecule
{
	MolecularBond bond;
	vector<Atom> atoms;
};
int main()
{
	vector<Molecule> molecules;

	for (int i = 0; i < 3; i++)
	{
		cout << "Create Molecule Number " << i + 1 << endl;

		Molecule molecule;
		molecules.push_back(molecule);

		cout << "How many atoms are in this molecule: ";
		int numberofAtoms;
		cin >> numberofAtoms;

		for (int j = 0; j < numberofAtoms; j++)
		{
			cout << "Create Atom Number " << j + 1 << endl;
			Atom atom;

			cout << "Atomic Number: ";
			cin >> atom.atomicNumber;

			cout << "Atom Name: ";
			cin >> atom.name;

			cout << "Abbreviation: ";
			cin >> atom.abbreviation;

			cout << "Atomic Weight: ";
			cin >> atom.weight;

			molecules.back().atoms.push_back(atom);
			cout << endl;
		}
		cout << "What is the bond type: \n 1. Covalent \n 2. Ionic \n 3. Metallic \n 4. Hydrogen Bonding \n 5. VanDeerWaals \n";
		cout << "Make a selection: ";

		int bondType;
		cin >> bondType;

		switch (bondType)
		{
		case 1:
			molecules.back().bond = MolecularBond::covalent;
			break;
		case 2:
			molecules.back().bond = MolecularBond::ionic;
			break;
		case 3:
			molecules.back().bond = MolecularBond::metallic;
			break;
		case 4:
			molecules.back().bond = MolecularBond::hydrogenBonding;
			break;
		case 5:
			molecules.back().bond = MolecularBond::vanDerWaals;
			break;
		}
		cout << endl;


	}

	return 0;
}