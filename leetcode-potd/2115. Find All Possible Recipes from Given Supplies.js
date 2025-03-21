ou have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

 

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
 

Constraints:

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.




/**
 * @param {string[]} recipes
 * @param {string[][]} ingredients
 * @param {string[]} supplies
 * @return {string[]}
 */
var findAllRecipes = function (recipes, ingredients, supplies) {
    let graph = new Map();
    let inDegree = new Map();
    let available = new Set(supplies);
    let queue = [];

    // Step 1: Build Graph & In-Degree Map
    for (let i = 0; i < recipes.length; i++) {
        let recipe = recipes[i];
        let ingredientList = ingredients[i];

        inDegree.set(recipe, ingredientList.length); // Set initial in-degree

        for (let ingredient of ingredientList) {
            if (!graph.has(ingredient)) {
                graph.set(ingredient, []);
            }
            graph.get(ingredient).push(recipe);
        }
    }

    // Step 2: Add Available Supplies to Queue
    for (let item of supplies) {
        queue.push(item);
    }

    let result = [];

    // Step 3: Process Recipes in BFS Order
    while (queue.length > 0) {
        let ingredient = queue.shift(); // Get available ingredient

        if (inDegree.has(ingredient) && inDegree.get(ingredient) === 0) {
            result.push(ingredient); // Valid recipe found
        }

        if (graph.has(ingredient)) {
            for (let recipe of graph.get(ingredient)) {
                inDegree.set(recipe, inDegree.get(recipe) - 1);
                if (inDegree.get(recipe) === 0) {
                    queue.push(recipe); // Recipe is now creatable
                }
            }
        }
    }

    return result.filter((r) => recipes.includes(r)); // Only return valid recipes  
};
