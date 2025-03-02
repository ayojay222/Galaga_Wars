using UnityEngine;

public class Bullet : MonoBehaviour
{
    public float speed = 10f;

    void Update()
    {
        transform.Translate(Vector3.up * speed * Time.deltaTime);
    }

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Enemy"))
        {
            GameController gameController = FindObjectOfType<GameController>();
            gameController.AddScore(10);
            Destroy(other.gameObject);
            Destroy(gameObject);
        }
    }
}
