using UnityEngine;

public class Enemy : MonoBehaviour
{
    public float speed = 2f;
    public GameObject enemyBulletPrefab;
    public float shootInterval = 3f;

    void Start()
    {
        InvokeRepeating("Shoot", shootInterval, shootInterval);
    }

    void Update()
    {
        transform.Translate(Vector3.down * speed * Time.deltaTime);
    }

    void Shoot()
    {
        Instantiate(enemyBulletPrefab, transform.position, Quaternion.identity);
    }
}
