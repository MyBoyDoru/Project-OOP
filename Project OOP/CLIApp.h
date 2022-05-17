#pragma once
#include "CLIController.h"
#include "ActionManager.h"

class CLIApp
{
public:
	/// Default constructor for the CLI app
	CLIApp();
    /// Alternate constructor with controller
    /// @param [in] CLIController Controller associated to the CLIApp class
    CLIApp(CLIController c);
	/// Starts the loop
    void Start();
	/// <summary>
	/// Adds an Item* and its stock to the shop
	/// </summary>
	/// <param name="x">Item* to be added</param>
	/// <param name="stock">Stock of the Item to be added</param>
	void addElement(Item* x, int stock);
private:

	CLIController controller; ///< The associated controller for this app
	ActionManager manager;
	void clear(); ///< Cross platform clear function
	void pause(); ///< Cross platform pause function
	/// <summary>
	/// Sets up an Item to be added to the inventory
	/// </summary>
	void setup();
	/// <summary>
	/// Prints all the elements in the Shop
	/// </summary>
	void viewAll();
	/// <summary>
	/// Removes an element with the given ID
	/// </summary>
	void remove();
	/// <summary>
	/// Modifies an element with the given ID
	/// </summary>
	void modify();
	/// <summary>
	/// Menu for filtering
	/// </summary>
	void filter();
	void undo();
	void addAction(Action* action);
	/// <summary>
	/// Input for the CPU etc etc
	/// </summary>
	/// <returns></returns>
	CPU* inputCPU();
	GPU* inputGPU();
	RAM* inputRAM();
	PSU* inputPSU();
	MOBO* inputMOBO();
	Storage* inputStorage();
	Case* inputCase();
};

