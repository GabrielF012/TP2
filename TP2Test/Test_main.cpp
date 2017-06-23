#include <gtest/gtest.h>
#include "Graphe.h"
#include "ReseauInterurbain.h"

using namespace TP2;

TEST(GrapheTestsSimples, GrapheConstruitRenvoieSonNombreDeSommet) {
	size_t nbSommet = 5;
	Graphe g(nbSommet);
	ASSERT_EQ(nbSommet, g.getNombreSommets());
}

TEST(GrapheTestsSimples, GrapheConstruitRenvoieSonNouveauNombreDeSommet) {
	size_t nbSommet = 5;
	Graphe g(nbSommet);
	size_t newNbSommet = 9;
	g.resize(newNbSommet);
	ASSERT_EQ(newNbSommet, g.getNombreSommets());
}

TEST(GrapheTestsSimples, GrapheConstruitRenvoieSonNomDunSommet) {
	size_t nbSommet = 5;
	std::string nSommet = "Quebec";
	Graphe g(nbSommet);
	g.nommer(2, nSommet);
	ASSERT_EQ(nSommet, g.getNomSommet(2));
}

TEST(GrapheTestsSimples, GrapheConstruitRenvoieArcExiste) {
	Graphe g;
	g.ajouterArc(0, 1, 1.75, 50.25);
	ASSERT_TRUE(g.arcExiste(0, 1));
}

TEST(GrapheTestsSimples, GrapheConstruitEnleveArcPuisValide) {
	Graphe g;
	g.ajouterArc(0, 1, 1.75, 50.25);
	g.enleverArc(0, 1);
	ASSERT_EQ(0, g.getNombreArcs());
}

TEST(GrapheTestsSimples, GrapheConstruitVerifierNbArc) {
	Graphe g;
	g.ajouterArc(0, 1, 1.75, 50.25);
	ASSERT_EQ(1, g.getNombreArcs());
}

TEST(GrapheTestsSimples, GrapheConstruitVerifierNbArcApresAvoirEnleverArc) {
	Graphe g;
	g.ajouterArc(0, 1, 1.75, 50.25);
	g.ajouterArc(0, 2, 2.25, 15.30);
	g.ajouterArc(1, 3, 2.5, 33.50);
	g.enleverArc(0, 2);
	ASSERT_EQ(2, g.getNombreArcs());
}

TEST(GrapheTestsSimples, GrapheConstruitNommeUnSommetPuisRetourneSonNumero) {
	Graphe g;
	g.nommer(0, "Quebec");
	g.nommer(1, "Montreal");
	g.nommer(2, "Trois-Riviere");
	ASSERT_EQ(1, g.getNumeroSommet("Montreal"));
}

TEST(GrapheTestsSimples, GrapheConstruitCreerArcPuisRetournePonderationDuree) {
	Graphe g;
	g.ajouterArc(0, 1, 2.5, 25.50);
	auto temps = g.getPonderationsArc(0, 1);
	ASSERT_EQ(2.5, temps.duree);
}

TEST(GrapheTestsSimples, GrapheConstruitCreerArcPuisRetournePonderationCout) {
	Graphe g;
	g.ajouterArc(0, 1, 2.5, 25.50);
	auto montant = g.getPonderationsArc(0, 1);
	ASSERT_EQ(25.50, montant.cout);
}

TEST(GrapheReseauSimples, ReseauConstruit) {

}