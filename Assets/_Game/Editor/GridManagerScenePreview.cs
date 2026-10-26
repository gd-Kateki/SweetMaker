#if UNITY_EDITOR
using UnityEditor;
using UnityEngine;

[CustomEditor(typeof(GridManager))]
internal sealed class GridManagerScenePreview : Editor
{
    private const string PreviewPreferenceKey =
        "SweetMaker.GridManagerScenePreview.Enabled";

    private static readonly Color FillColor =
        new Color(0.25f, 0.78f, 0.88f, 0.16f);

    private static readonly Color OutlineColor =
        new Color(0.45f, 0.9f, 1f, 0.9f);

    private static readonly Color LabelColor =
        new Color(0.8f, 0.95f, 1f, 0.9f);

    public override void OnInspectorGUI()
    {
        DrawDefaultInspector();

        EditorGUILayout.Space();
        bool showPreview = EditorPrefs.GetBool(
            PreviewPreferenceKey,
            true);
        bool newShowPreview = EditorGUILayout.Toggle(
            "Show Scene Board Preview",
            showPreview);

        if (newShowPreview != showPreview)
        {
            EditorPrefs.SetBool(
                PreviewPreferenceKey,
                newShowPreview);
            SceneView.RepaintAll();
        }
    }

    [DrawGizmo(GizmoType.NonSelected | GizmoType.Selected)]
    private static void DrawGridPreview(
        GridManager grid,
        GizmoType gizmoType)
    {
        if (EditorApplication.isPlaying ||
            Camera.current == null ||
            Camera.current.cameraType != CameraType.SceneView ||
            !EditorPrefs.GetBool(PreviewPreferenceKey, true))
        {
            return;
        }

        if (grid == null || !grid.gameObject.activeInHierarchy)
            return;

        var serializedGrid = new SerializedObject(grid);
        int columns = serializedGrid.FindProperty("columns").intValue;
        int rows = serializedGrid.FindProperty("rows").intValue;
        float cellSize = serializedGrid.FindProperty("cellSize").floatValue;
        float spacing = serializedGrid.FindProperty("spacing").floatValue;
        var cellPrefab = serializedGrid.FindProperty("cellPrefab")
            .objectReferenceValue as GridCell;

        if (columns <= 0 || rows <= 0)
            return;

        SpriteRenderer prefabRenderer =
            cellPrefab != null
                ? cellPrefab.GetComponent<SpriteRenderer>()
                : null;
        Sprite cellSprite =
            prefabRenderer != null
                ? prefabRenderer.sprite
                : null;

        Vector2 spriteSize = cellSprite != null
            ? cellSprite.bounds.size
            : Vector2.one;
        Vector2 spriteCenter = cellSprite != null
            ? cellSprite.bounds.center
            : Vector2.zero;
        float step = cellSize + spacing;
        float gridWidth = (columns - 1) * step;
        float gridHeight = (rows - 1) * step;
        Vector2 startPosition = new Vector2(
            -gridWidth / 2f,
            gridHeight / 2f);

        Color previousColor = Handles.color;
        var corners = new Vector3[4];
        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                Vector2 cellPosition =
                    startPosition +
                    new Vector2(column * step, -row * step);
                Vector2 localCenter =
                    cellPosition + spriteCenter * cellSize;
                Vector2 halfSize = spriteSize * Mathf.Abs(cellSize) * 0.5f;

                Vector3 bottomLeft = grid.transform.TransformPoint(
                    new Vector3(
                        localCenter.x - halfSize.x,
                        localCenter.y - halfSize.y,
                        0f));
                Vector3 topLeft = grid.transform.TransformPoint(
                    new Vector3(
                        localCenter.x - halfSize.x,
                        localCenter.y + halfSize.y,
                        0f));
                Vector3 topRight = grid.transform.TransformPoint(
                    new Vector3(
                        localCenter.x + halfSize.x,
                        localCenter.y + halfSize.y,
                        0f));
                Vector3 bottomRight = grid.transform.TransformPoint(
                    new Vector3(
                        localCenter.x + halfSize.x,
                        localCenter.y - halfSize.y,
                        0f));

                corners[0] = bottomLeft;
                corners[1] = topLeft;
                corners[2] = topRight;
                corners[3] = bottomRight;
                Handles.DrawSolidRectangleWithOutline(
                    corners,
                    FillColor,
                    OutlineColor);

                Handles.color = LabelColor;
                Handles.Label(
                    grid.transform.TransformPoint(
                        new Vector3(localCenter.x, localCenter.y, 0f)),
                    $"{row + 1},{column + 1}");
                Handles.color = previousColor;
            }
        }

        Handles.color = previousColor;
    }
}
#endif
