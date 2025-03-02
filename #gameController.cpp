using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;

public class GameController : MonoBehaviour
{
    public GameObject playerPrefab;
    public GameObject enemyPrefab;
    public Transform enemySpawnPoint;
    public float enemySpawnInterval = 2f;
    public Text scoreText;

    private int score = 0;
    private List<GameObject> enemies = new List<GameObject>();

    void Start()
    {
        InvokeRepeating("SpawnEnemy", enemySpawnInterval, enemySpawnInterval);
        UpdateScore(0);
    }

    void SpawnEnemy()
    {
        GameObject enemy = Instantiate(enemyPrefab, enemySpawnPoint.position, Quaternion.identity);
        enemies.Add(enemy);
    }

    public void AddScore(int value)
    {
        score += value;
        UpdateScore(score);
    }

    void UpdateScore(int newScore)
    {
        scoreText.text = "Score: " + newScore;
    }
}
